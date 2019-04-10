//Code below referenced from: https://www.kirupa.com/react/creating_single_page_app_react_using_react_router.htm?fbclid=IwAR3pMlncEMjKZMwi9iexcB_K_w6Oj1aGubV9T_wMhJ7PK47FyaIkfVrpN7M

import React, { Component } from "react"; //imports react component
 
class Prototype extends Component { //prototype component
  render() { //renders page
    return ( //returns html
      <div>
      <center><h1>Instructions</h1></center> //instructions to start the game
        <center><p><strong>If you want to play the prototype, please click to play. If the player wishes to go right, then a hand gesture to the right will be displayed. If the player wishes to go left, then a left hand gesture would be displayed. If the player wishes to go up, then they would need to put two hands together. If gestures are recognisable to the Arduino, then the LEDs will light up. </strong></p></center>
      <center><a href="http://saravananpandian.panel.uwe.ac.uk/phaserdemo/"><img src="phaserhomepage001.png"></img></a></center> //image that links the game to the react app
      </div>

    );
  }
}
 
export default Prototype;