import React from 'react'
import BarChart from './components/map'

function App() {

  return (
    <div className="App">

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