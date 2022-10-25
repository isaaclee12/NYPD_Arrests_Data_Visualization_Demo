# from nypd_arrests_api.models import Arrests
from rest_framework import routers
from .views import ArrestsViewSet, TestViewSet

router = routers.SimpleRouter()

router.register(r'data', ArrestsViewSet, basename="data") #ArrestsViewSet, basename="arrests")
router.register(r'test', TestViewSet, basename="test") #ArrestsViewSet, basename="arrests")

# Insert more routes here as needed

urlpatterns = [
]

urlpatterns += router.urls