from django.shortcuts import render

from rest_framework import viewsets
from rest_framework.response import Response

from .models import Arrests, TestModel
from .serializers import ArrestsSerializer, TestSerializer
import time

class ArrestsViewSet(viewsets.ModelViewSet):

    starttime = time.perf_counter()

    queryset = Arrests.objects.filter(arrest_precinct__exact=25)

    http_method_names = ['get']

    def list(self, request):

        endtime = time.perf_counter()   

        runtime = endtime - self.starttime

        print("Query completed in: " + str(runtime) + "s") 

        serializer = ArrestsSerializer(self.queryset, many=True)

        # print("test:", self.queryset, serializer.data)

        return Response(serializer.data)



class TestViewSet(viewsets.ModelViewSet):

    queryset = TestModel.objects.all()

    http_method_names = ['get']

    def list(self, request):

        serializer = TestSerializer(self.queryset, many=True)

        return Response(serializer.data)
