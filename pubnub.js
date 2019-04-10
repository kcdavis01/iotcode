
///////////////////////////Code referenced from: Adam Bavosa (https://gist.github.com/ajb413)//////////////////////////////
   const pubnub = new PubNub({
      publishKey : 'pub-c-77e55fe1-b562-423d-b74e-9cf40a46a0ea', //Our publish key from PubNub
      subscribeKey : 'sub-c-69f33614-4c85-11e9-bfba-22653a49d911'//Our subscribe key from PubNub
});

pubnub.addListener({ //Response of the call is handled by adding a Listener
        status: function(statusEvent) {
        if (statusEvent.category === "PNConnectedCategory") {  //Notified of connectivity via the listener, on establishing connection of the statusEvent.category
        publishSampleMessage();
        }
    },
    message: function(msg) { //Object that contains numbers (sensor data).
		console.log(msg); // Lets user know the sensor data in the Phaser Game Console.
        console.log(msg.message.eon.sensor);
		gesture = msg.message.eon.sensor;
        console.log(key); //Links to gesture within game.
    },
    presence: function(presenceEvent) { // handle presence
    }
});

console.log("Subscribing.."); //Lets users know they are subscribing to the PubNub channel from accessing the Phaser Game.
   var msg = pubnub.subscribe({ //Causes the client to create an open TCP socket to the PubNub Real-Time Network and begin listening for messages on a specified channel.
    channels: ['project'] //Specifies channel name to publish messages to.
});

function publishSampleMessage() {
   let message = { 
       title: "greeting",
       description: "Game is now running!" 
  }
  let channel = "project";
 console.log("Game is now running.");
}
