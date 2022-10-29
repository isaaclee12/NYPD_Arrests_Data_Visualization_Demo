from django.db import models

# Create your models here.
class Arrests(models.Model):

    # id = models.AutoField(primary_key=True)

    # `ARREST_KEY` BIGINT,
    arrest_key = models.PositiveBigIntegerField()

    # `ARREST_DATE` DATE,
    arrest_date = models.CharField(max_length=10)

    # `PD_CD` SMALLINT,
    pd_cd = models.IntegerField(default=None, null=True, blank=True)

    # `PD_DESC` VARCHAR(200),
    pd_desc = models.CharField(max_length=200, default=None, null=True, blank=True)

    # `KY_CD` SMALLINT,
    ky_cd = models.IntegerField(default=None, null=True, blank=True)

    # `OFNS_DESC` VARCHAR(200),
    ofns_desc = models.CharField(max_length=200, default=None, null=True, blank=True)

    # `LAW_CODE` VARCHAR(20),
    law_code = models.CharField(max_length=20)

    # `LAW_CAT_CD` CHAR(1),
    # Law Category Choices
    MISDEMEANOR = 'M'
    FELONY = 'F'
    VIOLATION = 'V'
    NONE = None

    LAW_CAT_CD_CHOICES = [
        (MISDEMEANOR, 'Misdemeanor'),
        (FELONY, 'Felony'),
        (VIOLATION, 'Violation'),
        (NONE, 'N/A')
    ]

    # TODO: Decide on a name for this
    law_cat_cd = models.CharField(
        max_length=1,
        choices=LAW_CAT_CD_CHOICES,
        default=NONE
        )
        

    # `ARREST_BORO` CHAR(1),
    # Law Category Choices
    MANHATTAN = 'M'
    KINGS = 'K'
    QUEENS = 'Q'
    BRONX = 'B'
    STATEN_ISLAND = 'S'
    NONE = None

    ARREST_BORO_CHOICES = [
        (MANHATTAN, 'Manhattan'),
        (KINGS, 'Kings'),
        (QUEENS, 'Queens'),
        (BRONX, 'Bronx'),
        (STATEN_ISLAND, 'Staten Island'),
        (NONE, 'N/A'),
    ]

    # TODO: Decide on a name for this
    arrest_boro = models.CharField(
        max_length=1,
        choices=ARREST_BORO_CHOICES,
        default = NONE
    )


    # `ARREST_PRECINCT` TINYINT,
    arrest_precinct = models.IntegerField()

    # `JURISDICTION_CODE` SMALLINT,
    jurisdiction_code = models.IntegerField()

    # `AGE_GROUP` VARCHAR(10),
    age_group = models.CharField(max_length=10)

    # `PERP_SEX` CHAR(1),
    # GENDER CHOICES

    MALE = 'M'
    FEMALE = 'F'

    GENDER_CHOICES = [
        (MALE, 'Male'),
        (FEMALE, 'Female'),
        (NONE, 'None'),
    ]

    perp_sex  = models.CharField(
        max_length=1,
        choices=GENDER_CHOICES,
        default = NONE
        )

    # `PERP_RACE` VARCHAR(100),
    perp_race = models.CharField(max_length=100)

    # `X_COORD_CD` MEDIUMINT,
    x_coord_cd = models.IntegerField()

    # `Y_COORD_CD` MEDIUMINT,
    y_coord_cd = models.IntegerField()
    
    # `Latitude` DECIMAL(11,9),
    latitude = models.DecimalField(max_digits=11,decimal_places=9)
    
    # `Longitude` DECIMAL(15,13),
    longitude = models.DecimalField(max_digits=15,decimal_places=13)

    # `Lon_Lat` VARCHAR(150)
    long_lat = models.CharField(max_length=150)

class TestModel(models.Model):
    name = models.CharField(max_length=100)
    age = models.IntegerField()

"""BoroughHeatMap: A day by day count of the number of crimes in each borough.
Assuming the model contains records from 1/1/06 to 12/31/21, there only be
5,475 entries, which is far easier to process than the 5+ million in the 
raw data. This data will be used for a day to day visualization
of arrests in each borough."""
# TODO: Push this model to the table, then query data to it on the backend to speed things up
class BoroughHeatMap(models.Model):
    arrest_date = models.CharField(max_length=10, null=True)
    manhattan_arrests = models.IntegerField(null=True)
    kings_arrests = models.IntegerField(null=True)
    queens_arrests = models.IntegerField(null=True)
    bronx_arrests = models.IntegerField(null=True)
    staten_island_arrests = models.IntegerField(null=True)