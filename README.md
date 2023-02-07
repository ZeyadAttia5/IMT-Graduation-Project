# IMT-Graduation-Project

Description of the project:-

    Make a login system using the ATMEGA32 and HC-05 bluetooth module.

How to use this repo and what to expect:-

    If you want to use this repo, you can clone it and upload the code to your AVR microcontroller and connect the circuit.
    Then, download (Bluetooth Terminal HC-05) from Google's Play Store and connect it to the circuit.

    You will be prompted to enter a username:
    There are 3 usernames that correspond to 3 passwords, respictively.

    If you send "user1" via the app, you will be prompted to enter a password ("pass1").
                "user2"                                                       ("pass2")
                "user3"                                                       ("pass3")

    entering wrong username or password 3 consecutive times will put send a high voltage on (Port A, Pin 4)
    and the enter an infinte loop.
