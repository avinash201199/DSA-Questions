#Menu Driven Program to perform various tasks

while True:
      #Taking String as input from user
      str1 = input("Enter a string: ")
      n = len(str1)
      print()

      #Defining a menu for a user
      print("Main Menu")
      print("-"*55)
      print("1. Reverse the string")
      print("2. Alternate characters LowerCase and UpperCase")
      print("3. Find the repeating characters in the string")
      print("4. Encode the string by adding 2 to each ASCII value")
      print("5. Exit")
      print("-"*55)
      print()
      
      #Taking choice from the user
      opt = int(input("Enter your option (1-5): "))
      
      #Reverse a string
      if opt == 1:
            for i in range(-1,-n-1,-1):
                  print(str1[i],end="")
            print()
            print()    
      
      #Alternate Characters LowerCase to UpperCase and vice-versa       
      if opt == 2:
            str2 = ""
            for i in range(n):
                  if i % 2 ==0:
                        str2 = str2 + str1[i].upper()
                  else:
                        str2 = str2 + str1[i].lower()
            print(str2)
            print()

      #Find Repeaeting Character in string
      if opt == 3:
          print("Repeating characters are: ")
          for i in range(n):
                  ctr = 1
                  for j in range(i+1,n):
                        if str1[i] == str1[j]:
                              ctr = ctr + 1
                              str1 = str1[:j] + ' ' + str1[j+1:]
                              
                  if ctr>1 and str1[i] != ' ':
                        print(str1[i], end=" ")
          print()
          print()
        
      #Encoding string
      if opt == 4:
            str2 = ""
            for i in range(n):
                  asc = chr(ord(str1[i]) + 2)
                  str2 = str2 + asc
            print(str2)
            print()
      else:
          break


