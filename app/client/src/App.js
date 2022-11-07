import React, {useState, useEffect} from 'react'
import BarChart from './components/map'
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

      <p>asdfasdf</p>

      <BarChart/> 

      <nav>
        <a href="/">Heatmap</a>
        <a href="/">About</a>
      </nav>

      {/* TABLE */}
      <div>
        <table>
            <tbody>
              {rows.map(rows=>
                <tr key={rows.arrest_date}>
                  <td>{rows.arrest_date}</td>
                  <td>{rows.manhattan_arrests}</td>
                  <td>{rows.kings_arrests}</td>
                  <td>{rows.queens_arrests}</td>
                  <td>{rows.bronx_arrests}</td>
                  <td>{rows.staten_island_arrests}</td>
                </tr>
              )}
            </tbody>
        </table>
      </div>

      <Routes>
        <Route path></Route>
      </Routes>

    </div>
  );
}

export default App;