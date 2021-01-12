#pragma once

// the rabin-karp string matching algorithm


        using std::size_t;
        using std::string;

        #define ALPHABET 256
        #define Q 101

        bool rabin_karp(const std::string& pattern, const std::string& text) {
            size_t n = text.length();
            size_t m = pattern.length();
            int p = 0;
            int t = 0;
            int h = 1;

            // Calculate the hash value of pattern
            for (int i = 0; i < m; i++) {
                h = (h * ALPHABET) % Q;  // precompute
                p = (ALPHABET * p + pattern[i]) % Q;
                t = (ALPHABET * t + text[i]) % Q;
            }

            // Slide the 'pattern' over 'text' by one
            for (int i = 0; i < n - m; i++) {
                // check the hash values
                if (p == t) {
                    // check the characters one by one (check for false positives)
                    int j = 0;
                    for (; j < m; j++) {
                        if (text[i + j] != pattern[j]) {
                            break;
                        }
                    }

                    if (j == m) {
                        return true;
                    }
                }

                // Calculate has value of next window of 'text'
                // Remove leading digit, add trailing digit.
                if (i < n - m) {
                    t = (ALPHABET * t - text[i] * h + text[i + m]) % Q;  // clever update
                    // we might get negative values of t, converting it to positive.
                    if (t < 0) {
                        t = t + Q;
                    }
                }
            }

            return false;
        }

        void prepare_match(const std::string& pattern, std::vector<int>& b) {
            int i = 0;
            int j = -1;
            size_t m = pattern.length();

            b.resize(m);
            b[0] = -1;   // starting values

            while (i < m) {  // pre-process the pattern string
                while (j >= 0 && pattern[i] != pattern[j]) {
                    j = b[j];  // if different, reset j using b
                }

                i += 1;
                j += 1;          // if same advance both pointers
                b[i] = j;
            }
        }

        std::vector<int> prefix_table(const std::string& pattern) {
            size_t len = pattern.length();
            std::vector<int> table(len, 0);

            int k = 0;
            for (int i = 1; i < len; i++) {

                while (k > 0 && pattern[k+1] != pattern[i]) {
                    k = table[k];
                }

                if (pattern[k+1] == pattern[i]) {
                    k += 1; // the longest prefix str_k is also a proper suffix of str_i
                }
                table[i] = k;
            }

            return table;
        }
