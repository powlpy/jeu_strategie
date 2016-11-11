#include "game.h"

// C'est un test tout ne devrait pas etre dans le run
#include <gf/Event.h>
#include <gf/Font.h>
#include <gf/RenderWindow.h>
#include <gf/Sprite.h>
#include <gf/Text.h>
#include <gf/Window.h>


void Game::run(){
	// Create the main window and the renderer
  gf::Window window("Example", { 640, 480 });
  gf::RenderWindow renderer(window);
  // Load a sprite to display
  gf::Texture texture;
  if (!texture.loadFromFile("sprite.png")) {
    exit(EXIT_FAILURE);
  }
  gf::Sprite sprite(texture);
  sprite.setPosition({ 300, 200 });
  // Create a graphical text to display
  /*gf::Font font;
  if (!font.loadFromFile("DroidSans.ttf")) {
    return EXIT_FAILURE;
  }*/
  /*gf::Text text("Hello gf!", font, 50);
  text.setPosition({ 100, 100 });*/
  renderer.clear(gf::Color::White);
  // Start the game loop
  while (window.isOpen()) {
    // Process events
    gf::Event event;
    while (window.pollEvent(event)) {
      switch (event.type) {
        case gf::EventType::Closed:
          window.close();
          break;
        default:
          break;
      }
    }
    // Draw the entities
    renderer.clear();
    renderer.draw(sprite);
    //renderer.draw(text);
    renderer.display();
  }
}