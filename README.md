# Helldivers2Menu farts

<p align="center">
   Helldivers2Menu is a Cheat Menu for the popular Game Helldivers 2.
</p>

## Disclaimer
This project is for Educational Use only. We do not condone this software being used to gain an advantage against other people. I made this project for my university project to show how cheating software works and how it is possible to block these manipulations in the future.

## Compile (Configurations)
Please compile the project in **Release** mode. Debug does not work properly and gets detected by GG.

### Version Proxy (version.dll)
Will automatically be loaded by the Game itself if the dll is in the game directory.

### How to Run
1. Move the `version.dll` into the game directory in `/bin`
2. Change the Launch Options in Steam for the game into `--use-d3d11` 
3. Start the game
4. Press DELETE to show the menu
5. For performance increase, change into fullscreen mode (Dx11 being funky in HD2)

### Running on Proton (Version Proxy Only)
First you will need protontricks, you can install it with your packager of choice.

1. Make sure you are running Helddivers 2 under Proton  
   You can check by going to **Properties -> Compatibility**
3. Put version.dll into Helldivers 2 bin folder
4. Run `protontricks --gui`
5. Choose **HELLDIVERS 2**
6. Click on **Select the default wineprefix** and then **OK**
7. Click on **Run winecfg** and then **OK**
8. In the configuration window, click on **Libraries**
9. Type `version` into the **New override for library** input
10. Click **Add** and then **Apply**
11. Helldivers2Menu should now work properly in the game

### Default Hotkeys
- Show Menu - DELETE

## Screenshot
<p align="center">
   <img src="screenshot.png">
</p>

## Contributing
1. Fork it (<https://github.com/BitCrackers/Helldivers2Menu/fork>)
2. Create your feature branch (`git checkout -b feature/fooBar`)
3. Commit your changes (`git commit -am 'Add some fooBar'`)
4. Push to the branch (`git push origin feature/fooBar`)
5. Create a new Pull Request
