import React, {Component} from 'react'
import * as d3 from 'd3';

const Map = () => {

    // d3 boilerplate
    // let margin = {top: 0, bottom: 0, left: 0, right: 0},
    //     height = 400 - margin.top - margin.bottom,
    //     width = 800 - margin.left - margin.right;

    // create svg object
    var width = 1280, height = 800;

    var svg = d3.select("#map").append("svg")
            .attr("width", width)
            .attr("height", height);

    var projection = d3.geoPath()
            .azimuthal()
            .mode("equidistant")
            .origin([-98, 38])
            .scale(1500)
            .translate([640, 360]);

    var path = d3.geoPath()
            .projection(projection);

    var borough = svg.append("svg:g")
        .attr("id", "Borough");

    d3.json("NYC_Boroughs.json", function(error, nyc) {
        if (error) return console.error(error);
        borough.selectAll("path").data(nyc.features)
                .enter().append("svg:path")
                .attr("d",path)
                .attr("class", function(d){
                    return "class" + d.id;
                })
                .style("fill", function(){
                    return "hsl(" + Math.random() * 360 + ",60%,30%)";
                });
    });

    // test object
    // let map = d3.select("#map") // select all html objects with ID map
        // .append("p")
        // .text("test")

    // read in topojson
        // d3.json("NYC_Boroughs.json", function (data) {
        //     console.log(data);
        //     map.append(data);
        // });
        // .await(ready)

    return( 
        <div id="map">
        </div>
    )
}

export default Map;