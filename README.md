In progress, Note to self: everything should be snake case


## Data Sources:
- NYPD Arrests Data (Historic): https://data.cityofnewyork.us/Public-Safety/NYPD-Arrests-Data-Historic-/8h9b-rp9u
- Topojson of NYC Boroughs: https://github.com/HarryBirtles/NYC-Maps-and-Data

# TODO:

### DATABASE CHANGES:
- Db is way too big (5 million + entries) to just process via django
- need to have small datasets with pre-analyzed results

### RESULTS TO RENDER:

- Heatmap of Data over time by borough
  - Have a table with rows as years with and cols as crime counts by borough, e.g: 
  
  {"1987": 'Manhattan': 79, 'Brooklyn': 84 'Bronx': 64, ...}

- Heatmap of racial disparities
  - Table with rows as years with cols as racial disparities in arrests by borough, e.g:   {"1987", 'Manhattan': 1.84, ...}, wherein the disparity can be selected by how much more likely you would be arrested that year by X race (One table for each race, maybe? Should we lump together races? This is a big ethics question.)

- More analyses can be created as needed, but let's start with just this to keep it simple, and adjust as needed.

### Front-End to Back-End pipeline:
- Create calls to Django from React that return data that renders on the client

### D3.js
- Implement d3.js to render the data


# Hours Log:
- 10/24/2022 (6.5 hours)
    - Established Boilerplate
    - Initiated Models and Database

- 10/25/2022 (5 hours)
    - Configured models, serializers, viewsets, and sqlite3 database
    - Began seeking better "big" data analysis solutions

- 10/28/2022 (4 hours)
    - Fiddled with big data storage and analysis
    - Hit roadblocks with everything. Great!
    
- 10/29/2022 (11am-)


---

# How to:

Clone the repository, open a command line instance within the folder:


## Front End Initialization:

- `cd app`
- `cd client`
- `npm install`
- `yarn start`

## Back End Initialization:


- `cd app`
- `pip install -r requirements.txt`
- `python manage.py runserver`

---

Data Info:

id,
ARREST_KEY,
ARREST_DATE,
PD_CD,
PD_DESC,
KY_CD,
OFNS_DESC,
LAW_CODE,
LAW_CAT_CD, 
ARREST_BORO,
ARREST_PRECINCT,
JURISDICTION_CODE,
AGE_GROUP,
PERP_SEX,
PERP_RACE,
X_COORD_CD,
Y_COORD_CD,
Latitude,
Longitude,
Lon_Lat