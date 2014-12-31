//HANGMAN PROGRAM EXAMPLE

public class hangManProject


import java.util.Scanner;

// provided by
// Nur Timurlenk, Okan Dukkanci, Neslihan Kahyaoglu, Efe Subasi, Gizem Ozbaygin
// (Section # 07)

public class hangManProject
{
    public static void main( String[] args)
    {
        Scanner scan = new Scanner( System.in);



        // CONSTANTS

        // VARIABLES
        int totalMistake = 0;
        boolean b = false;
        // PROGRAM CODE


        showWelcome();
        SecretWord word = new SecretWord();
        System.out.println("Your clue: " + word.getClue());
        KeyboardInput input = new KeyboardInput();
        while (totalMistake < 4 && !word.isSolved())
        {
            System.out.println(word);
            char c = input.getNewLetter();
            if (!word.update(c))
                totalMistake = totalMistake + 1 ;
        }
        if (word.isSolved())
            System.out.println("Great, you done it.");
        else
            System.out.println("Sorry, too many errors.");

    }

        public static void showWelcome()
        {
            System.out.println( "Welcome to Hangman Game:)!!" );
        }

}



public class SecretWord


public class SecretWord
{
    String clue, visible, secret;

public SecretWord()
{
    String [] wordList = { "Umbrella", "Richard Feynman", "American Gangster", "The Silmarillion" };

    String [] clueList = { "Rihanna's song", "Nobel Prize in Physics", "Denzel Washington", "Tolkien" };
    int rand;
    rand = (int) (Math.random()*4);
    secret = wordList[rand];
    clue = clueList[rand];
    int wordLength = secret.length();

    visible = "";

    for ( int i = 0; i < secret.length(); i++)
    {
        char c = secret.charAt(i);

        if ( c == ' ' )
            visible += c;
        else
            visible += '_';
    }
}

public String getClue()
{
    return clue;
}

public String toString()
{
    // String s = "";
    // for(int i = 0; i < wordLength; i++)
    //    s = s + "_ ";
    // return s;

    return visible;
}

    // provided by Group 4 and 8
    public boolean update(char c)
    {
        char[] secretArray = new char [secret.length()];
        char[] visibleArray = new char [secret.length()];
        String s = "";
        boolean contains = false ;

        //We make the String secret an array
        for(int i = 0; i < secret.length(); i++)
        {
            secretArray[i] = secret.charAt(i);
            visibleArray[i] = visible.charAt(i);
        }

        //We are uptading our empty visible array
        for(int k = 0; k < secret.length();k++)
        {

            if(secretArray[k] == c)
            {
                visibleArray[k] = c;
                contains = true;
            }
        }
        //We are changing our visible array into the visible string
        for(int m=0; m < secret.length(); m++ )
        {
            s = s + visibleArray[m];
        }
        visible = s;

        return contains;
   }
    //This is a method to check if the secret word is solved
    public boolean isSolved()
    {
        return secret.equalsIgnoreCase(visible);
    }
}

public class KeyboardInput


import java.util.ArrayList;
import java.util.Scanner;

public class KeyboardInput
{
    // Properties
    ArrayList<String> keyList ;
    boolean chosen;

    //Constructor
    public KeyboardInput()
    {
        keyList = new ArrayList<String>();
    }

    // Adds and stores the entered key in the Arraylist
    public void keyChosen( String key )
    {
        keyList.add( key );
    }

    // Checks if the entered key has been chosed before
    public boolean hasBeenChosen( String key)
    {
        chosen = keyList.contains( key );
        return chosen;
    }


    public char getNewLetter()
    {
        Scanner scan=new Scanner( System.in);

        char a;
        boolean chosen;
        String aTmp;    // used to convert a into a String for compatibility with Group 6

        do
        {
            System.out.println("Enter a Letter");
            a = scan.next().charAt( 0);
            aTmp = "" + a;
            chosen = hasBeenChosen( aTmp);
            if(!chosen)
                keyChosen( aTmp);
            else
            {
                System.out.println("You've already used that one. Please enter a new Letter");

            }


        }
        // we repeat the process until we're out of trials.
        while(chosen);

        return a;
    }
}
