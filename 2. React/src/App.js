import './App.css';
import Blogs from './components/Blogs';
import FormCustom from './components/FormCustom';
import {BrowserRouter as Router,Routes,Route} from 'react-router-dom';

function App() {
  return (
    <Router>
    <div className="App">
    <Routes>
      <Route exact path="/FormRoute" element={<FormCustom/>}> </Route>
      <Route excat path="/" element= {<Blogs/>}> </Route>
    </Routes>
    </div>
    </Router>
    
  );
}

export default App;
