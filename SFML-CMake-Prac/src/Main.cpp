#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main()
{
	sf::Window mainWindow(
		sf::VideoMode({ 1028, 768 }),
		"This is a Window",
		sf::Style::Default,
		sf::State::Windowed
	);

	mainWindow.setFramerateLimit(60);

	while (mainWindow.isOpen())
	{
		while (const std::optional event = mainWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				mainWindow.close();
			}
		}
	}

	// After closing the main window, the second window will open 2 seconds later.

	sf::sleep(sf::seconds(2));

	sf::Window secondWindow(
		sf::VideoMode({ 600, 400 }),
		"This is a second window!",
		sf::Style::Default,
		sf::State::Windowed
	);

	while (secondWindow.isOpen())
	{
		sf::Window thirdWindow(
			sf::VideoMode({ 320, 180 }),
			"This is a third window!",
			sf::Style::Default,
			sf::State::Windowed
		);

		while (thirdWindow.isOpen())
		{
			while (const std::optional event = thirdWindow.pollEvent())
			{
				if (event->is<sf::Event::Closed>())
				{
					thirdWindow.close();
				}
			}
		}

		// These are on the same thread so the third window's loop will block the second window's until closed.
		// After closing the third window, the second window's loop will continue and remake the third window.
		// Next set them on separate threads.

		while (const std::optional event = secondWindow.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
			{
				secondWindow.close();
			}
		}
	}

	return 0;
}
