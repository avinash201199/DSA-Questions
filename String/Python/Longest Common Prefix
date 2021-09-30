# Write a function to find the longest common prefix string amongst an array of strings.
# If there is no common prefix, return an empty string "".


def longestCommonPrefix(strs):
        if not strs: return ''
        m, M, i = min(strs), max(strs), 0
        for i in range(min(len(m),len(M))):
            if m[i] != M[i]: 
                break
            else: 
                i += 1
        return m[:i]


if __name__ == "__main__":
    strs=["app","apple","appreature"]
    print(longestCommonPrefix(strs))
