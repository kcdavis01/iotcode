
/////////////////////Phaser code below referenced from tutorial: https://phaser.io/tutorials/making-your-first-phaser-3-game/index///////


  var StateMain = {

    preload: function () {
    game.load.spritesheet('diver', 'images/diver.png, 80, 111);
    },
    create: function (){
    this.diver=game.add.sprite(game.world.centerX,game.world.centerY, "diver");
    }
    update: function (){

}

}