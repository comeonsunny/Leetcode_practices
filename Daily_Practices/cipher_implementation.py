# Define a function to get the numerical value of a letter
def letter_value(letter):
  # Use ord() to get the ASCII code of the letter
  # Subtract 65 for uppercase letters or 97 for lowercase letters
  # Use modulo 26 to get a value between 0 and 25
  if letter.isupper():
    return (ord(letter) - 65) % 26
  elif letter.islower():
    return (ord(letter) - 97) % 26
  else:
    return None

# Define a function to get the letter corresponding to a numerical value
def value_letter(value):
  # Use chr() to get the ASCII character of the value
  # Add 65 for uppercase letters or 97 for lowercase letters
  # Use modulo 26 to get a value between 0 and 25
  return chr((value % 26) + 65)

# Define a function to encrypt a plaintext using a key
def vigenere_encrypt(plaintext, key):
  # Initialize an empty string for the ciphertext
  ciphertext = ""
  # Initialize an index variable for the key
  key_index = 0
  # Loop through each character of the plaintext
  for char in plaintext:
    # Get the numerical value of the character and the key
    char_value = letter_value(char)
    key_value = letter_value(key[key_index])
    # If both values are valid, encrypt the character by adding the values and getting the corresponding letter
    if char_value is not None and key_value is not None:
      ciphertext += value_letter(char_value + key_value)
      # Increment the key index by one, wrapping around if necessary
      key_index = (key_index + 1) % len(key)
    # If either value is invalid, append the character as it is and do not increment the key index
    else:
      ciphertext += char
  # Return the ciphertext
  return ciphertext

# Define a function to decrypt a ciphertext using a key
def vigenere_decrypt(ciphertext, key):
  # Initialize an empty string for the plaintext
  plaintext = ""
  # Initialize an index variable for the key
  key_index = 0
  # Loop through each character of the ciphertext
  for char in ciphertext:
    # Get the numerical value of the character and the key
    char_value = letter_value(char)
    key_value = letter_value(key[key_index])
    # If both values are valid, decrypt the character by subtracting the values and getting the corresponding letter
    if char_value is not None and key_value is not None:
      plaintext += value_letter(char_value - key_value)
      # Increment the key index by one, wrapping around if necessary
      key_index = (key_index + 1) % len(key)
    # If either value is invalid, append the character as it is and do not increment the key index
    else:
      plaintext += char
  # Return the plaintext
  return plaintext

# Test the functions with some examples
plaintext = "hello"
key = 'key'
ciphertext = vigenere_encrypt(plaintext, key)
print(f"cipher({plaintext}, {key}) = {ciphertext}")

