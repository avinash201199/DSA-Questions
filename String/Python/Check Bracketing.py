'''
Author 28Pollux28
This program checks whether an expression bracketing is correct :
"({[]})" returns True
"{(][)}" returns False
'''

def main(str):
    print(verif_t(str))


def verif_t(l):
    list_elem = []
    for el in l:
        if el == "(" or el =="[" or el =="{":
            list_elem.append(el)
        elif el==")" or el=="]" or el=="}":
            if len(list_elem)!=0:
                if el == ")" and list_elem[-1]=="(":
                    list_elem.pop()
                elif el == "]" and list_elem[-1]=="[":
                    list_elem.pop()
                elif el == "}" and list_elem[-1]=="{":
                    list_elem.pop()
                else:
                    return False
            else:
                return False
    return len(list_elem)==0


if __name__ == '__main__':
    string = input("input string :")
    main(string)