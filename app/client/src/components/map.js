import React, {Component, useState, useEffect} from 'react'
import * as d3 from 'd3';

const Map = () => {

    const [mapData, setMapData] = useState([]);

    useEffect(() => {
        d3.json("NYC_Boroughs.json") //("https://github.com/HarryBirtles/NYC-Maps-and-Data/blob/master/NYC_Boroughs.topojson")
        .then((data) => {
            setMapData(data);
        })
        .catch((err) => {
            console.log("Error when loading map:", err);
        });
    }, [])


    // set up projection stuff for the svg
    const setMapProjection = function(mapData) {
        // use the geoAlbers map projection
        const projection = d3.geoAlbers();
        // adjust projection to fit area of map canvas
        projection
            .precision(0)
            .rotate([90, 0, 0])
            .fitExtent(
            [
                [0, 0],
                [960, 480],
            ],
            mapData
            );
        return projection;
        };

    //set map data to d3
    const path = d3.geoPath().projection(setMapProjection(mapData.data));

    console.log(path);

    d3.select("#map")
    .append(path)
    

    return( 
        <div id="map">
        </div>
    )
}

export default Map;