#ifndef vigenere_h
#define vigenere_h

#include <string>
#include <cctype>
#include <stdexcept>

/**
 * @brief A class for encrypting and decrypting messages using the Vigenere cipher.
 */
class Vigenere {
public:
    /**
     * @brief Constructs a Vigenere object with a given key.
     * @param key The key used for encryption and decryption (uppercase only).
     */
    Vigenere(const std::string& key);

    /**
     * @brief Destructor for the Vigenere class.
     */
    ~Vigenere();

    /**
     * @brief Encrypts a given message using the key.
     * @param msg The message to be encrypted (uppercase letters only).
     * @return The encrypted message in uppercase.
     */
    std::string encrypt(const std::string& msg) const;

    /**
     * @brief Decrypts an encrypted message using the key.
     * @param msg The encrypted message to be decrypted (uppercase letters only).
     * @return The decrypted message in uppercase.
     */
    std::string decrypt(const std::string& msg) const;

    /**
     * @brief Checks if an encrypted message matches the original after decryption.
     * @param encryptedMsg The encrypted message.
     * @param decryptedMessage The original message to compare after decryption.
     * @return True if the encrypted message decrypts to the original, false otherwise.
     */
    bool isEncrypted(const std::string& encryptedMsg, const std::string& decryptedMessage) const;

    /**
     * @brief Sets a new key for encryption and decryption.
     * @param key The new key (uppercase only).
     */
    void setKey(const std::string& key);

private:
    std::string key;

    /**
     * @brief Ensures the key repeats to match the message length.
     * @param msgLength The length of the message.
     * @return The extended key matching the message length.
     */
    std::string extendKey(size_t msgLength) const;

    /**
     * @brief Shifts a character by a given offset, wrapping around the alphabet.
     * @param c The character to shift.
     * @param offset The shift offset (positive for encryption, negative for decryption).
     * @return The shifted character.
     */
    char shiftChar(char c, int offset) const;
};

#endif
