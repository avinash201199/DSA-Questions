import java.util.*; 

public class FindDupChars
{ 
  public static void main(String args[]) 
  { 
    DupChars("Hello");
    DupChars("Hacktoberfest"); 
  } 
  
  public static void DupChars(String str) 
  { 
    char[] characters = str.toCharArray(); 
    for (Character ch : characters) 
    { 
      if (charMap.containsKey(ch)) 
      { 
        charMap.put(ch, charMap.get(ch) + 1); 
      } 
      else 
      { 
        charMap.put(ch, 1); 
      } 
    } 
  Set<Map.Entry<Character, Integer>> entrySet = charMap.entrySet(); 
    System.out.println("List of duplicate characters in the String '%s' %n", str); 
    for (Map.Entry<Character, Integer> entry : entrySet) 
    { 
      if (entry.getValue() > 1) 
      { 
        System.out.println("%s : %d %n", entry.getKey(), entry.getValue()); 
      } 
    } 
  } 
}


