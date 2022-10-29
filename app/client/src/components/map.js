import React, {Component} from 'react'
import * as d3 from 'd3';

class BarChart extends Component {
    
    componentDidMount() {
        this.drawChart()
    }

    drawChart() {
        const data = [12,5,6,2,7,9]
        const svg =  d3.select('.bar').append('svg').attr('width',700).attr('height',300);
        svg
            .selectAll('rect') // select all rect objects
            .data(data) // map data to those objects
            .enter() // enter inits the data vis
            .append('rect') // update those rects as data updates in real time
            .attr('x', (d, i) => i * 70) // map the position of ea. bar by the index of bar * 70, (d,i) inits the map of data to index
            .attr('y', 0) // keep y pos at 0
            .attr('width', 25) // set wth and ht
            .attr('height', (d,i) => d) // map data's values to each bar's height by initing then pulling the d var
            .attr('fill', 'green') // set inside color to green
    }
}

/*// Set margins here
var margin = {top: 0, left: 0, right: 0, bottom: 0},
    height = 900 - margin.top - margin.bottom;
    width = 600 - margin.left - margin.right;

// Set svg var
const svg = 

    // select any items with the class "map"
    d3.select('.map')

    // Add an svg object to those items, with it's attr's set as listed below
    .append('svg')
    .attr('height', height)
    .attr('width', width)

// Read in data
d3.queue()*/

export default BarChart;