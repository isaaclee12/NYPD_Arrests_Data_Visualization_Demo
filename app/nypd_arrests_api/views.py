from django.shortcuts import render

from rest_framework import viewsets
from rest_framework.response import Response

from .models import Arrests, TestModel
from .serializers import ArrestsSerializer, TestSerializer

class ArrestsViewSet(viewsets.ModelViewSet):

    queryset = Arrests.objects.filter(perp_race__exact="BLACK")[10:]

    http_method_names = ['get']

    def list(self, request):

        serializer = ArrestsSerializer(self.queryset, many=True)

        # Return to front end
        return Response(serializer.data)



class TestViewSet(viewsets.ModelViewSet):

    queryset = TestModel.objects.all()

    http_method_names = ['get']

    def list(self, request):

        serializer = TestSerializer(self.queryset, many=True)

        return Response(serializer.data)
