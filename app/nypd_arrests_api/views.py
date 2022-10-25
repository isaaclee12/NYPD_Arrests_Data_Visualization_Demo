from django.shortcuts import render

from rest_framework import viewsets
from rest_framework.response import Response

from .models import Arrests, TestModel
from .serializers import ArrestsSerializer, TestSerializer
import time

class ArrestsViewSet(viewsets.ModelViewSet):

    # Establish queryset
    query_start_time = time.perf_counter()

    queryset = Arrests.objects.filter(perp_race__exact="BLACK")[10:]

    http_method_names = ['get']

    def list(self, request):

        # Time the query
        query_end_time = time.perf_counter()   

        query_run_time = query_end_time - self.query_start_time

        print("Query completed in: " + str(query_run_time) + "s") 


        # Serialize the data
        serializer_start_time = time.perf_counter()   

        serializer = ArrestsSerializer(self.queryset, many=True)

        serializer_end_time = time.perf_counter()   

        serializer_run_time = serializer_end_time - serializer_start_time

        print("Serialization completed in: " + str(serializer_run_time) + "s") 

        print(serializer.data)


        # Return to front end
        return Response(serializer.data)



class TestViewSet(viewsets.ModelViewSet):

    queryset = TestModel.objects.all()

    http_method_names = ['get']

    def list(self, request):

        serializer = TestSerializer(self.queryset, many=True)

        return Response(serializer.data)
