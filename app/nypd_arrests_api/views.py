from django.shortcuts import render

from rest_framework import viewsets
from rest_framework.response import Response

from .models import Arrests, TestModel, BoroughHeatMap
from .serializers import ArrestsSerializer, TestSerializer, BoroughHeatMapSerializer

import pandas as pd

from django.db import connection


class ArrestsViewSet(viewsets.ModelViewSet):

    queryset = Arrests.objects.filter(perp_race__exact="BLACK")[10:]

    http_method_names = ['get']

    def list(self, request):

        serializer = ArrestsSerializer(self.queryset, many=True)

        # Return to front end
        return Response(serializer.data)



class TestViewSet(viewsets.ModelViewSet):

    # queryset = TestModel.objects.all()

    queryset = str(TestModel.objects.all().query)
    df = pd.read_sql_query(queryset, connection)

    df.head()

    http_method_names = ['get']

    def list(self, request):

        # serializer = TestSerializer(self.queryset, many=True)

        return Response(self.df) #serializer.data)

class BoroughHeatMapViewSet(viewsets.ModelViewSet):

    queryset = BoroughHeatMap.objects.all()

    http_method_names = ['get']

    def list(self, request):

        serializer = BoroughHeatMapSerializer(self.queryset, many=True)

        print(serializer.data)

        # Return to front end
        return Response(serializer.data)

