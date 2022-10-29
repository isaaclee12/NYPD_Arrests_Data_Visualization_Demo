import React from 'react'
import BarChart from './components/map'
import {Route, Routes} from 'react-router-dom'

function App() {

  return (
    <div className="App">

      <p>asdfasdf</p>

      <BarChart/> 

      <nav>
        <a href="/">Heatmap</a>
        <a href="/">About</a>
      </nav>

      <Routes>
        <Route path></Route>
      </Routes>

    </div>
  );
}

export default App;