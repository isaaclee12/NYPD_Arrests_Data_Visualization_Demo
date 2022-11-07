# from nypd_arrests_api.models import Arrests
from rest_framework import routers
from .views import ArrestsViewSet, TestViewSet, BoroughHeatMapViewSet

router = routers.SimpleRouter()

router.register(r'data', ArrestsViewSet, basename="data")
router.register(r'test', TestViewSet, basename="test")
router.register(r'heatmap', BoroughHeatMapViewSet, basename="heatmap")

# Insert more routes here as needed

urlpatterns = [
]

urlpatterns += router.urls