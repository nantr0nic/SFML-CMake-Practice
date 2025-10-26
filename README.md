# Practice with SFML 3.0 & CMake
### And some other stuff, like EnTT and TGUI (later)
This is a repo to test some SFML 3.0 + CMake stuff and practice some SFML coding.

Got EnTT and TGUI to work with SFML and CMake as well. I've commented out TGUI for now
because I'm not using it yet and it extends generation/build time quite a bit.

With SFML, I'm trying to practice proper "architecture" right off the bat 
rather than having to refactor a bunch later.

Using a combination of some books on but they're using SFML 2.5/2.6, so I'm bouncing between
those books for architecture/design patterns and the SFML 3.0 documentation for the actual code.

My previous project used two CMakeLists.txt files (one in root, one in the 'project' folder)
but I'm trying out a single CMakeLists.txt file in the root for this project to see how that goes.