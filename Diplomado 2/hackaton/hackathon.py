import random
import time

"""
@authors: Digital Dreamers Group
    
- Brayan Steven Barón Díaz           : brayanbaron.2004@gmail.com
- Gabriela Rozo Camargo              : gabrielarozocamargo@gmail.com
- Miguel Angel Maldonado Bautista    : miguebaptist@gmail.com
- Juana Valentina Mendoza Santamaría : juana.mendoza@usantoto.edu.co 
- Santiago Ricardo Ramirez           : sricardoramirez14@gmail.com

"""

def guess_number():
    """
    First game: Guess number game.

    Returns
    -------
    None.

    """
    counter = 0
    number = random.randint(1, 100)
    while True:
        counter += 1
        userN = int(input('Please, enter an intenger: '))
        if userN == number:
            print(
                f'Congratulations. You guessed the number: {number} in {counter} tries.')
            break
        elif userN >= number:
            print('Lower!')
        else:
            print('Higher!')
        if counter == 5:
            print(f'Sorry. You have lost the number was: {number}')
            break

def get_list(characters):
    number = random.randint(0, 4)
    for i in characters:
        for c in range(len(i)):
            if c == number:
                return characters[0][c]


def guess_good():
    """
    Second game: Mythological god.

    Returns
    -------
    None.

    """
    characters = [
        ["Zeus", "Man", "King of the gods", "Sky", "Thunders", "Eagle"],
        ["Poseidon", "Man", "God of the sea", "Earthquakes", "storms", "Horse"],
        ["Hades", "Man", "God of the underworld", "Riches", "Ghosts", "Cerberus"],
        ["Afrodita", "Woman", "Goddess of love", "Beauty", "Love", "Pigeon"],
        ["Apolo", "Man", "God of the sun and music", "Arts", "Music", "Lira"]
    ]

    character_win = characters[random.randint(0, 4)]

    attempts = 0
    while attempts < 5:
        attempts += 1
        character = input("attempt #" + str(attempts) +
                          ": Guess the characters of Greek mythology: ")
        if character == character_win[0]:
            print("¡Congratulations, you guessed the characters!")
            return
        else:
            print("Clue:", end=" ")
            if "Man" in character_win:
                print("The characters is a man", end=", ")
            else:
                print("The characters is a Woman", end=", ")
            if "God" in character_win[2]:
                print("Is a god", end=", ")
            else:
                print("Is a goddess", end=", ")
            print("One of its features is: ",
                  character_win[random.randint(2, 5)])

    print("Sorry, you lost. The winning characters was", character_win[0])
    

def memory_game():
    """
    Third game: Memory Game

    Returns
    -------
    None.

    """
    attempts = 5
    level = 4
    secuencia = []
    answer = []
    counter = 1
    while attempts > 0 and counter < 6:
        secuencia = [random.randint(1, 9) for x in range(level)]
        print(f"The sequence is: {secuencia}")
    
        print("repeat the sequence:")
        answer = [int(input()) for x in range(level)]
    
        if answer == secuencia:
            print("Correct")
            level += 1
        else:
            print("Incorrect. restarting game.")
            level = 4
            attempts -= 1
        counter += 1
    print("Game over. Thanks for playing.")

        
def get_number():
    """ 
    Get a number from the user.

    Returns:
        int: user's number.
    """
    while True:
        number = int(input('⚠ Please, enter a number of an operation: '))
        if 0 < number < 5: 
            break
        else:
            print('The number is not between 1 to 5. Please, try again.\n')
    return number

def welcome_message():
    """ 
    Show the welcome message.
    
    """
    print("".ljust(90, '-'), "\n")
    print('⚡ Welcome to code Wizards Play Menu! \n'.center(90))
    welcome_menu()


def welcome_menu():
    """ 
    Show the main menu.
    
    """
    print("".ljust(90, '-'), "\n")
    print(''.join(('🖥️ Games: \n',
    '1. Guess the number\n',
    '2. Guess who\n',
    '3. Memory\n',
    '4. Exit of the menú')))
    print("\n".ljust(90, '-'), "\n")
    
def wait():
    time.sleep(0.5)
    input('Press ENTER to return to the main menu...\n')

def set_operations():
    """ 
    Call other functions.
    
    """
    while True:
        welcome_message()
        number = get_number()
        if number == 1:
            guess_number()
            wait()
        elif number == 2:
            guess_good()
            wait()
        elif number == 3:
            memory_game()
            wait()
        else:
            print('Thank you very much for trying our games. Come back soon! - Code Wizards.')
            break
    
def main():
    set_operations()
    
main()