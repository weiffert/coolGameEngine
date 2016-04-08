#include "MissileExploder.h"
#include "SystemManager.h"
#include <SFML/Graphics.hpp>


MissileExploder::MissileExploder()
{
}


MissileExploder::~MissileExploder()
{
}


//This function currently explodes a missile, and creates a circle explosion
//This function is called from MissileLauncher
void MissileExploder::control(sf::Window * window, Entity * missile)
{
  double rate;
  rate = 1;
  double tempRadius;
  if (!(missile->getComponent("ExplosionPhase").at(0) == -2)) //Makes sure the explosion didn't already happen
  {
      //If it doesn't already have an explosion, create one (property "ExplosionPhase" is 0)
     if (missile->getComponent("ExplosionPhase").at(0) == 0)
     {
      missile->getComponent("ExplosionPhase")->deleteData();
      missile->getComponent("ExplosionPhase")->addDataInt(1);
     }
      
      //Check radius
      if (missile->getComponent("ExplosionRadius")->getDataInt().at(0) == 20)
      {
        missile->getComponent("ExplosionPhase")->deleteData();
        missile->getComponent("ExplosionPhase")->addDataInt(-1);
      }
    //Check to see if the explosion disappears
    if(missile->getComponent("ExplosioRadius").at(0) - 
    rate * missile->getComponent("ExplosionPhase").at(0) < 0)
    {
    missile->getComponent("ExplosionRadius")->deleteData();
       missile->getComponent("ExplosionRadius")->addDataDouble(0);
       missile->getComponent("ExplosionPhase")->deleteData();
       missile->getComponent("ExplosionPhase")->addDataInt(-2);
      
    }
    else
    {
      tempRadius = missile->getComponent("ExplosionRadius")->getDataDouble().at(0);
      tempRadius += rate * missile->getComponent("ExplosionPhase")->getDataDouble().at(0);
      missile->getComponent("ExplosionRadius")->deleteData();
      missile->getComponent("ExplosionRadius")->addDataInt(tempRadius);
    }
  }
  
  //Actually draw the circle/explosion
  sf::CircleShape explosion;
  explosion.setRadius(missile->getComponent("ExplosionRadius")->getDataDouble().at(0));
  explosion.setFillColor(sf::Color::Red);
  explosion.setPosition(missile->getComponent("ExplodingPosition")->getDataDouble().at(0), 
  missile->getComponent("ExplodingPosition")->getDataDouble().at(1));
  window->draw(explosion);
  
}
