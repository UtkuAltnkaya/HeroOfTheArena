<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
<div align="center">

  [![Contributors][contributors-shield]][contributors-url]
  [![Forks][forks-shield]][forks-url]
  [![Stargazers][stars-shield]][stars-url]
  [![Issues][issues-shield]][issues-url]
  [![MIT License][license-shield]][license-url]

</div>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/UtkuAltnkaya/HeroOfTheArena">
    <img src="./screenshots/logo.png" alt="Logo" width="100%" height="80">
  </a>

  <h3 align="center">HERO OF THE ARENA</h3>
  <p align="center">
    A Turn-based Game  
    <br />
    <a href="https://github.com/UtkuAltnkaya/HeroOfTheArena"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/UtkuAltnkaya/HeroOfTheArena">View Demo</a>
    ·
    <a href="https://github.com/UtkuAltnkaya/HeroOfTheArena/issues">Report Bug</a>
    ·
    <a href="https://github.com/UtkuAltnkaya/HeroOfTheArena/issues">Request Feature</a>
  </p>
</div>

<!-- CREATORS -->
<br/>

<h1 align="center">Creators</h1>

<table width="100%">
  <tr>
    <td align ="center"><a href="https://github.com/alperrkilic"><img src="https://avatars.githubusercontent.com/u/103885392?v=4" width="65%" style="padding-left:20px"></a></td>
    <td align ="center"><a href="https://github.com/UtkuAltnkaya"><img src="https://avatars.githubusercontent.com/u/88653820?v=4" width="65%"></a></td>
    <td align ="center"><a href="https://github.com/AtesBurak1"><img src="https://avatars.githubusercontent.com/u/97343351?v=4" width="65%" style="padding-right:20px"></a></td>
  </tr>
  <tr>
    <td align="center"><a href="https://github.com/alperrkilic">Bayram Alper KILIÇ</a></td>
    <td align="center"><a href="https://github.com/UtkuAltnkaya">Utku ALTINKAYA</td>
    <td align="center"><a href="https://github.com/AtesBurak1">Burak ATEŞ</td>
  </tr>
</table>

<br/>
<br/>

<!-- product image -->
<div style="margin-top:50px" align ="center">
    <img src="./screenshots/fight_1.png" alt="Logo" width="75%" height="75%">
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#gameplay">Gameplay</a></li>
    <!-- <li><a href="#contributing">Contributing</a></li> -->
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

Hero of The Arena is designed as a Turn-based game where our hero fights against a boss. There are six characters. Five of the characters are warriors and one is archer. All of the pixel art, character animes, are free assets and taken from <a href="itch.io">itch.io</a>. Our code is open-source and could be contributed. However, commercializing is forbidden.

To improve our work:
* We welcome comments and criticisms. You can contact us by sending an e-mail.
* You can report errors in the Issues section.
* We welcome new teammates who want to work with us.

 Although over 200 hours were spent producing, the game still needs many improvements. We will continue to add new features in the future. This is our first game we developed, we hope you all like the game. For other projects, please follow us.


<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

Hero Of The Arena is made with C++ and SFML. No such game engine was used in the project, so all animations, physics and logic were done manually.

* <a href="https://cplusplus.com/">
    <img src="https://img.shields.io/badge/C ++-004488?style=for-the-badge&logo=c%2B%2B&logoColor=white">
</a>

* [![SFML][SFML]][SFML-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started

You need a gcc compiler before playing the game. The game consumes about 120mb of RAM and 200mb of storage.

### Prerequisites

You can download g++ from the link below.
* g++
  ```sh
  https://gcc.gnu.org/
  ```

### Installation and Compiling

_You can download and install the game from our website. You can also run the game with a compiler. For this, clone our project and create object files using Makefile commands._

-  <a href=" https://www.hero-of-the-arena.netlify.app">Download</a>


<!-- USAGE EXAMPLES -->
## Gameplay

Below you can find some of the UI and character skills. Music options, store and character selection are available for the UI. There is a chance to beat the boss with the purchased items, but the character will most likely die if the wrong items are bought. As for the characters, each character has 3 attack skills, one special attack (R) and the other two basic attack (Q,W). Special Attack can't be used often as it consumes more mana than other skills. Each turn regenerates the character's mana so that the special attack becomes available. On some rounds, attacking may not be the best option. Therefore, you can choose defense (E) for a Turn to regenerate mana for the special attack.

<br/>
<br/>

<h1 align="center">User Interface</h1>

<table>
  <tr>
        <td align ="center"><img src="./screenshots/main_menu.png" alt="Logo" width="75%" height="75%"></img></td>
        <td align ="center"><img src="./screenshots/character_menu.png" alt="Logo" width="75%" height="75%"></img></td>
  </tr>
  <tr>
        <td align ="center">Main Menu</td>
        <td align ="center">Character Menu</td>
  </tr>
    <tr>
        <td align ="center"><img src="./screenshots/options.png" alt="Logo" width="75%" height="75%"></img></td>
        <td align ="center"><img src="./screenshots/shop.png" alt="Logo" width="75%" height="75%"></img></td>
  </tr>
  <tr>
        <td align ="center">Options</td>
        <td align ="center">Shop</td>
  </tr>
</table>

</br>
</br>

<h1 align="center">Character Animations</h1>

<table>
      <tr>
        <td align ="center"><img src="./screenshots/fight_2.png" alt="Logo" width="75%" height="75%"></img></td>
        <td align ="center"><img src="./screenshots/fight_3.png" alt="Logo" width="75%" height="75%"></img></td>
  </tr>
  <tr>
        <td align ="center">Fire Knight</td>
        <td align ="center">Blade Keeper</td>
  </tr>
  <tr>
        <td align ="center"><img src="./screenshots/fight_4.png" alt="Logo" width="75%" height="75%"></img></td>
        <td align ="center"><img src="./screenshots/fight_5.png" alt="Logo" width="75%" height="75%"></img></td>
  </tr>
  <tr>
        <td align ="center">Ground Monk</td>
        <td align ="center">Leaf Archer</td>
  </tr>
  <tr>
        <td align ="center"><img src="./screenshots/fight_6.png" alt="Logo" width="75%" height="75%"></img></td>
        <td align ="center"><img src="./screenshots/fight_7.png" alt="Logo" width="75%" height="75%"></img></td>
  </tr>
  <tr>
        <td align ="center">Water</td>
        <td align ="center">Wind</td>
  </tr>
</table>

_For more details, please visit the [HOTA Website](https://example.com)_

<!-- <p align="right">(<a href="#readme-top">back to top</a>)</p> -->
<!-- CONTRIBUTING -->
<!-- ## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request -->

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the GPL-3.0 License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Bayram Alper KILIÇ - alperkilicbusiness@gmail.com

Utku ALTINKAYA - utkualtinkayabusiness@outlook.com

Burak ATEŞ - burakatesbusiness@gmail.com


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Below you can find the assets and resources we used to make the game.

* [Character Audios](https://dillonbecker.itch.io/sdap)
* [Chierit Elemental Characters and NPC's](https://chierit.itch.io/)
* [Background Image](https://edermunizz.itch.io/free-pixel-art-hill)
* [Music Pack](https://ansimuz.itch.io/action-music-pack-1)
* [Image Shields](https://shields.io)
* [Heart for UI](https://swooshwhoosh.itch.io/heartsui)
* [UI table asset](https://henrysoftware.itch.io/pixel-interface)
* [Main Menu Font](https://lana-ro.itch.io/sra-free-pixel-font-pack)
* [Main Menu Header Font](https://pixel-salvaje.itch.io/free-font-for-pixelart-titles)
* [Character Menu Cards](https://opengameart.org/content/pixel-card-assets)
* [Demon Slime Boss](https://chierit.itch.io/boss-demon-slime)
* [Frost Guardian Boss](https://chierit.itch.io/boss-frost-guardian)


<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/UtkuAltnkaya/HeroOfTheArena.svg?style=for-the-badge 
[contributors-url]:https://github.com/UtkuAltnkaya/HeroOfTheArena/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/UtkuAltnkaya/HeroOfTheArena.svg?style=for-the-badge
[forks-url]: https://github.com/UtkuAltnkaya/HeroOfTheArena/network/members
[stars-shield]: https://img.shields.io/github/stars/UtkuAltnkaya/HeroOfTheArena.svg?style=for-the-badge
[stars-url]: https://github.com/UtkuAltnkaya/HeroOfTheArena/stargazers
[issues-shield]: https://img.shields.io/github/issues/UtkuAltnkaya/HeroOfTheArena.svg?style=for-the-badge
[issues-url]: https://github.com/UtkuAltnkaya/HeroOfTheArena/issues
[license-shield]: https://img.shields.io/github/license/UtkuAltnkaya/HeroOfTheArena.svg?style=for-the-badge
[license-url]: https://github.com/UtkuAltnkaya/HeroOfTheArena/blob/main/LICENSE

[SFML]: https://img.shields.io/badge/SFML-ffffff?style=for-the-badge&logo=sfml&logoColor=green
[SFML-url]: https://www.sfml-dev.org/

