public class LinkedListExample
{
    public static void main(String[] args)
    {
        LinkedList<String> list = new LinkedList<String>();
 
        //Adding elements at the end of the list
 
        list.add("JAVA");
 
        list.add("J2EE");
 
        list.add("JSP");
 
        list.add("SERVLETS");
 
        list.add("JDBC");
 
        //Printing the elements of list
 
        System.out.println(list);      //Output : [JAVA, J2EE, JSP, SERVLETS, JDBC]
 
        String s = "JSP";
 
        //Checking whether list contains "JSP"
 
        boolean contains = list.contains(s);
 
        if(contains)
        {
            //If list contains "JSP", printing it's index
 
            System.out.println(list.indexOf(s));      //Output : 2
        }
 
        s = "STRUTS";
 
        //Checking whether list contains "STRUTS"
 
        contains = list.contains("STRUTS");
 
        if(contains)
        {
            //If list contains "STRUTS", printing it's index
 
            System.out.println(list.indexOf(s));
        }
    }
}
