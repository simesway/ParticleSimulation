#include "MainWindow.hpp"

MainWindow::MainWindow(){
	window.create(sf::VideoMode(width, height), name, sf::Style::Close);
	window.setFramerateLimit(30);
	
	pSystem.setPosition(20,20);
	pSystem.setup();
	menu.setPosition(1000,20);
	menu.setup(pSystem.gValues, pSystem.effectDistance);
}

void MainWindow::open(){
	pSystem.reset();
	draw();
	state.reset();

	while(window.isOpen()){
		
		loopEvents();

		if(state.start || state.step) 
			pSystem.update();

		draw();

		if(state.step) 
			state.step = false;
	}
}

void MainWindow::draw(){
	window.clear(color.background);
	pSystem.draw(window, state.start, state.clear);
	menu.draw(window);
	window.display();
}

void MainWindow::loopEvents(){
	sf::Event event;
	while(window.pollEvent(event)){

		menu.handleEvent(event);

		if(event.type == sf::Event::KeyPressed){
			using eKey = sf::Keyboard;
			switch(event.key.code){
				
				case eKey::Num1:
					pSystem.OnOff(0);
					pSystem.draw(window, state.start, state.clear);
					window.display(); break;
				case eKey::Num2:
					pSystem.OnOff(1);
					pSystem.draw(window, state.start, state.clear);
					window.display(); break;
				case eKey::Num3:
					pSystem.OnOff(2);
					pSystem.draw(window, state.start, state.clear);
					window.display(); break;
				case eKey::Num4:
					pSystem.OnOff(3);
					pSystem.draw(window, state.start, state.clear);
					window.display(); break;
				case eKey::Num0:
					pSystem.setZero();
					break;

				case eKey::G:
					pSystem.randomizeG(-5,5); 
					pSystem.reset();
					if(!state.start)
						draw();
					break;

				case eKey::Space:
					state.start = state.start ? false : true; break;
				case eKey::C:
					state.clear = state.clear ? false : true; break;
				case eKey::Right:
					state.step = state.step ? false : true; break;
				case eKey::R:
					pSystem.reset();
					window.clear(color.background);
					if(!state.start)
						draw();
					break;
				case eKey::Escape:
					window.close(); break;
			}
		}		

		if(event.type == sf::Event::Closed)
			window.close();
	}
}
