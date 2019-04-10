//Code below referenced from: https://www.kirupa.com/react/creating_single_page_app_react_using_react_router.htm?fbclid=IwAR3pMlncEMjKZMwi9iexcB_K_w6Oj1aGubV9T_wMhJ7PK47FyaIkfVrpN7M

import React, { Component } from "react"; //imports React component
import { //Importing from the react-router-dom NPM package
  Route,
  NavLink,
  HashRouter
} from "react-router-dom";
import Home from "./Home"; //import Home component

import Prototype from "./Prototype"; //import Prototype component
 
class Main extends Component { //component returns the html
  render() { //renders the page
    return (
      <HashRouter> //define our routing region, provides foundation for the navigation and browser history
        <div>
         <center> <h2>Prototype solution to enhance the experience of instant messaging using the possibilities of the Internet of Things (IoT).</h2></center> //center tagged text
          <ul className="header">
            <li><NavLink exact to="/">Home</NavLink></li> //sets our navigation link
           
            <li><NavLink to="/Prototype">Prototype</NavLink></li> //sets the navigation link
          </ul>
          <div className="content">

            <Route exact path="/" component={Home}/> //ensures that route is only active if the path is an exact match for what being loaded
            
            <Route path="/Prototype" component={Prototype}/>//route path that renders the component  prop (path determine when the route is active)
             
          </div>
        </div>
      </HashRouter> 
    );
  }
}
 
export default Main;