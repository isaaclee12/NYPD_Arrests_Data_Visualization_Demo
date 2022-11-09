import React, {Component, useState, useEffect} from 'react'
import * as d3 from 'd3';

const Map = () => {

    const [mapData, setMapData] = useState([]);

    useEffect(() => {
        console.log("LOADING")
        d3.json("Borough_Boundaries.geojson") //("https://github.com/HarryBirtles/NYC-Maps-and-Data/blob/master/NYC_Boroughs.topojson")
            .then((data) => {
                setMapData(data);
                console.log("Map data:", mapData);
            })
            .catch((err) => {
                console.log("Error when loading map:", err);
            })
        
        /*async function fetchJson() {
            return await d3.json("Borough_Boundaries.geojson") //("https://github.com/HarryBirtles/NYC-Maps-and-Data/blob/master/NYC_Boroughs.topojson")
        }

        fetchJson().then((data) => {
                setMapData(data);
                setTimeout(function(){
                    console.log("Map data:", mapData);
                }, 500); 
            })
            .catch((err) => {
                console.log("Error when loading map:", err);
            });*/
    }, []);

    // create an svg in all div's with id "map" with a certain width and height
    const svg = d3.select("#map")
                .append('svg')
                .attr('width', 900)
                .attr('height', 600);

    // create <g>'s in the <svg>'s
    const g = svg.append('g');

    // Setup the projection:
    const bounds = d3.geoBounds(mapData.topology);
    const centerX = d3.sum(bounds, (d) => d[0]) / 2;
    const centerY = d3.sum(bounds, (d) => d[1]) / 2;
    const myProjection = d3.geoMercator()
    .center([centerX, centerY]);

    // Create a geographic path generator and set its projection:
    const path = d3.geoPath()
        .projection(myProjection);

    g.selectAll('path')
        .data(mapData.features)
        .enter()
        .append('path')
        .attr('d', path);



    

    


    return( 
        <div id="map">
        </div>

        
    )
}

export default Map;