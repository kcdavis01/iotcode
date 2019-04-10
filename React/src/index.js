//Code below referenced from: https://www.kirupa.com/react/creating_single_page_app_react_using_react_router.htm?fbclid=IwAR3pMlncEMjKZMwi9iexcB_K_w6Oj1aGubV9T_wMhJ7PK47FyaIkfVrpN7M

import React from "react"; //imports react component
import ReactDOM from "react-dom";  //imports ReactDOM
import Main from "./Main"; //imports main component
import "./index.css"; //imports the css 
 
ReactDOM.render(   //ReactDOM renders the Main component
  <Main/>, 
  document.getElementById("root")
);