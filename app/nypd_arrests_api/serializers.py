from django.contrib.auth.models import User
from .models import Arrests, TestModel
from rest_framework import serializers

# These are serializers, i.e. the things that make 
# complex SQL data into Python native data

class ArrestsSerializer(serializers.ModelSerializer):
    class Meta:
        model = Arrests
        fields = (
            "id",
            "arrest_key",
            "arrest_date",
            "pd_cd",
            "pd_desc",
            "ky_cd",
            "ofns_desc",
            "law_code",
            "law_cat_cd",
            "arrest_boro",
            "arrest_precinct",
            "jurisdiction_code",
            "age_group",
            "perp_sex",
            "perp_race",
            "x_coord_cd",
            "y_coord_cd",
            "latitude",
            "longitude",
            "long_lat"
        )

class TestSerializer(serializers.ModelSerializer):
    class Meta:
        model = TestModel
        fields = ("id",     "name", "age")