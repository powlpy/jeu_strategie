#include "game.h"
#include "vector2d.h"
// C'est un test tout ne devrait pas etre dans le run
#include <gf/Event.h>
#include <gf/RenderWindow.h>
#include <gf/Window.h>
#include <gf/Shapes.h>
#include <gf/Clock.h>
#include <gf/UI.h>
#include <gf/Font.h>
#include <gf/Shape.h>


Game::Game()
: graphicsManager(objectsManager)
{
  //players[0] = Player();
  ArchetypeObject& a = objectsManager.addArchetype("mage1", "medievalUnit_01.png", Vector2d(30, 30));
  a.addModuleMoveable(30.);

  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(250, 250)));
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(350, 250)));
  objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], Vector2d(250, 350)));
}

void Game::run(){
  gf::Font font;
  gf::RenderWindow& renderer = graphicsManager.getRenderer();
  gf::Window& window = graphicsManager.getWindow();
  gf::DefaultUIRenderer uiRenderer(font);
  gf::UILayout  layout;
  gf::UI ui1(uiRenderer, layout);
  gf::UI ui2(uiRenderer, layout);
  gf::UI ui3(uiRenderer, layout);
  float scrollArea = 0;
  std::vector<int> idxObjectVector;

  gf::Vector2f mousePosition = {0, 0};
  // Start the game loop

  gf::Clock clock;
  while (window.isOpen()) {
    // Process events
    gf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case gf::EventType::Closed:
          window.close();
          break;
        case gf::EventType::MouseButtonPressed:
          if(event.mouseButton.button == gf::MouseButton::Left){
            if(objectsManager.getIdxObjectByPosition(Vector2d(event.mouseButton.coords.x, event.mouseButton.coords.y)) != -1) {
              bool selected = false;
              for(uint i = 0; i < idxObjectVector.size();){
                if(idxObjectVector[i] == objectsManager.getIdxObjectByPosition(Vector2d(event.mouseButton.coords.x, event.mouseButton.coords.y))){
                  idxObjectVector.erase(idxObjectVector.begin() + i);
                  selected = true;
                }
                else{
                  i++;
                }
              }
              if(!selected){
                idxObjectVector.push_back(objectsManager.getIdxObjectByPosition(Vector2d(event.mouseButton.coords.x, event.mouseButton.coords.y)));
              }
            }
            else{
              idxObjectVector.clear();
            }
          }
          else if(event.mouseButton.button == gf::MouseButton::Right){
            if(idxObjectVector.size() > 0){
              int indexX = 0;
              int indexY = 0; 
              for(auto& i : idxObjectVector){
                objectsManager.getObject(i).setGoal(Vector2d(event.mouseButton.coords.x+(indexX*30), event.mouseButton.coords.y+(indexY*30)));
                indexX++;
                if(indexX>10){
                  indexX = 0;
                  indexY++;
                }
              }
            }
          }
        break;
          case gf::EventType::MouseMoved:
            mousePosition = event.mouseCursor.coords;
            break;
          case gf::EventType::KeyPressed:
              if(idxObjectVector.size() > 0){
                PhysicObject& obj = objectsManager.getObject(idxObjectVector[0]);
                if(obj.isAlive()){
                  if(event.key.keycode != gf::Keycode::Backspace){
                    objectsManager.addObject(PhysicObject(objectsManager.getArchetypes()[0], obj.getPosition() + Vector2d(0, 30)));
                  }
                  else{
                    obj.kill();
                    idxObjectVector[0] = -1;
                  }
                }
              }
            break;
        default:
          break;
      }
      ui1.update(event);
      ui2.update(event);
      ui3.update(event);
    }
    ui1.clear();
    ui1.beginScrollArea("Scroll area", {10.0f, 490.0f, 200.0f, 200.0f}, &scrollArea);
    ui1.endScrollArea();

    ui2.clear();
    ui2.beginScrollArea("Scroll area", {220.0f, 540.0f, 700.0f, 150.0f}, &scrollArea);
    ui1.separatorLine();
    ui1.separator();
    ui2.endScrollArea();

    ui3.clear();
    ui3.beginScrollArea("Scroll area", {930.0f, 490.0f, 360.0f, 200.0f}, &scrollArea);
    ui3.button("Button1");
    ui3.button("Button2");
    ui3.button("Button3");
    ui3.endScrollArea();

    float dt = clock.restart().asSeconds();
    objectsManager.update(dt);

    renderer.clear(gf::Color::rgba(39.0f,174.0f,96.0f,255.0f));
    for(auto& i : idxObjectVector){
      gf::CircleShape circle({8});
      circle.setColor(gf::Color::Transparent);
      circle.setPosition({objectsManager.getObject(i).getPosition().x-1, objectsManager.getObject(i).getPosition().y+8});
      circle.setAnchor(gf::Anchor::Center);
      circle.setOutlineColor(gf::Color::Red);
      circle.setOutlineThickness(2.0f);
      renderer.draw(circle);
    }

    // Draw the entities
    objectsManager.render(renderer);

    renderer.draw(ui1);
    renderer.draw(ui2);
    renderer.draw(ui3);

    gf::RectangleShape rect({10, 10});
    rect.setColor(gf::Color::Red);
    rect.setPosition(mousePosition);
    rect.setAnchor(gf::Anchor::Center);
    renderer.draw(rect);

    renderer.display();
  }
} 
