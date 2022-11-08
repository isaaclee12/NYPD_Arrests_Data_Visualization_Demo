import React, {useState, useEffect} from 'react'
import Map from './components/map'
import {Route, Routes} from 'react-router-dom'

function App() {

  const [rows, setRows] = useState([])

  useEffect(() => {
    fetch("http://localhost:8000/arrests/heatmap" ,{ 
          method: "GET",
          mode: "cors",
        })

          .then((response) => response.json()
          .then(data => {
            console.table("Got back:", data);
            setRows(data);
          })
        
        // Error catcher
        ).catch(
          (error) => {
            console.log("Error fetching data: " + error)
          }
        )
  }, []);
  

  return (
    <div className="App">
      
      <Map/>

      {/* <nav class="py-10">
        <a href="/" class="ml-10">Heatmap</a>
        <a href="/" class="ml-10">About</a>
      </nav>

      <div>
        <table class="min-w-full">
            <thead class="border-b">
              <tr>
                <th scope="col" class="text-lg font-medium text-gray-900 px-6 py-4 text-center">arrest_date</th>
                <th scope="col" class="text-lg font-medium text-gray-900 px-6 py-4 text-center">manhattan_arrests</th>
                <th scope="col" class="text-lg font-medium text-gray-900 px-6 py-4 text-center">kings_arrests</th>
                <th scope="col" class="text-lg font-medium text-gray-900 px-6 py-4 text-center">queens_arrests</th>
                <th scope="col" class="text-lg font-medium text-gray-900 px-6 py-4 text-center">bronx_arrests</th>
                <th scope="col" class="text-lg font-medium text-gray-900 px-6 py-4 text-center">staten_island_arrests</th>
              </tr>
            </thead>
            <tbody class="text-center space-y-4">
              {rows.map(rows=>
                <tr key={rows.arrest_date} class="px-6 py-4 whitespace-nowrap text-sm font-medium text-gray-900">
                  <td class="text-lg text-gray-900 font-light px-6 py-4 whitespace-nowrap">{rows.arrest_date}</td>
                  <td class="text-lg text-gray-900 font-light px-6 py-4 whitespace-nowrap">{rows.manhattan_arrests}</td>
                  <td class="text-lg text-gray-900 font-light px-6 py-4 whitespace-nowrap">{rows.kings_arrests}</td>
                  <td class="text-lg text-gray-900 font-light px-6 py-4 whitespace-nowrap">{rows.queens_arrests}</td>
                  <td class="text-lg text-gray-900 font-light px-6 py-4 whitespace-nowrap">{rows.bronx_arrests}</td>
                  <td class="text-lg text-gray-900 font-light px-6 py-4 whitespace-nowrap">{rows.staten_island_arrests}</td>
                </tr>
              )}
            </tbody>
        </table>
      </div> */}

      {/* <Routes>
        <Route path></Route>
      </Routes> */}

    </div>
  );
}

export default App;