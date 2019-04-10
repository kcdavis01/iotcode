////Code below referenced from: https://www.kirupa.com/react/creating_single_page_app_react_using_react_router.htm?fbclid=IwAR3pMlncEMjKZMwi9iexcB_K_w6Oj1aGubV9T_wMhJ7PK47FyaIkfVrpN7M

import React, { Component } from "react"; //imports react component
 
class Home extends Component { //home component 
  render() {  //renders the page
    return ( //returns html elements
      <div>
        <center><h1>Welcome</h1></center> //html text
        <p><strong>Welcome to our project website for our Internet of Everything Module. On this website you will find our proposed prototype solution which is a playful solution to enhance the experience of instant messaging using the possibilities of the Internet of Things (IoT) based from a global issue, ocean pollution.</strong></p> //basic html text for home page

        <center><h1>Our Prototype</h1></center>//html text
        <p><strong>The game itself comprises of a screen of an ocean environment.  The player will clean their ocean by controlling the scuba diver and collecting plastic by a hand movement using the sensors attached to an Arduino. //instructions for the game
                   Within the game there is a score meter as well as a pollution meter. The players score meter would increment depending on whether they had cleaned the ocean. On the other hand, the pollution meter would be based on the time taken for them to clean their ocean. </strong></p>
      
      </div>

    );
  }
}
 
export default Home;