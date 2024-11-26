#include "vigenere.h"

Vigenere::Vigenere(const std::string& key) : key(key) {
    for (char c : key) {
        if (!std::isupper(c)) {
            throw std::invalid_argument("Key must contain only uppercase letters.");
        }
    }
}

Vigenere::~Vigenere() {}

std::string Vigenere::encrypt(const std::string& msg) const {
    std::string extendedKey = extendKey(msg.length());
    std::string encryptedMessage;

    for (size_t i = 0; i < msg.length(); ++i) {
        if (std::isupper(msg[i])) {
            int offset = extendedKey[i] - 'A';
            encryptedMessage += shiftChar(msg[i], offset);
        } else {
            encryptedMessage += msg[i];
        }
    }
    return encryptedMessage;
}

std::string Vigenere::decrypt(const std::string& msg) const {
    std::string extendedKey = extendKey(msg.length());
    std::string decryptedMessage;

    for (size_t i = 0; i < msg.length(); ++i) {
        if (std::isupper(msg[i])) {
            int offset = -(extendedKey[i] - 'A');
            decryptedMessage += shiftChar(msg[i], offset);
        } else {
            decryptedMessage += msg[i];
        }
    }
    return decryptedMessage;
}

bool Vigenere::isEncrypted(const std::string& encryptedMsg, const std::string& decryptedMessage) const {
    return encryptedMsg == encrypt(decryptedMessage);
}

void Vigenere::setKey(const std::string& newKey) {
    for (char c : newKey) {
        if (!std::isupper(c)) {
            throw std::invalid_argument("Key must contain only uppercase letters.");
        }
    }
    key = newKey;
}

std::string Vigenere::extendKey(size_t msgLength) const {
    std::string extendedKey;
    for (size_t i = 0; i < msgLength; ++i) {
        extendedKey += key[i % key.length()];
    }
    return extendedKey;
}

char Vigenere::shiftChar(char c, int offset) const {
    return 'A' + (c - 'A' + offset + 26) % 26;
}
