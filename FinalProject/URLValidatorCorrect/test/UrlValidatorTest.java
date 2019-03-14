import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach

public class UrlValidatorTest extends TestCase {

   public UrlValidatorTest(String testName) {
      super(testName);
   }
   
   //Manual Test
   public void testManualTest()
   {
	    UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	       
	       //testing some tlds
	       assertTrue(urlVal.isValid("http://corndog.io/"));//copied from browser
	       assertFalse(urlVal.isValid("http://corndog.icmb/")); //.icbm
	       assertTrue(urlVal.isValid("https://www.nytimes.com/")); //copied from browser
	       assertFalse(urlVal.isValid("https://www.nytimes.comunist/")); //copied from browser
	       assertTrue(urlVal.isValid("https://oregonstate.edu/"));
	       assertFalse(urlVal.isValid("https://oregonstate.udu/"));
	       
	       //testing some irregular characters
	       assertTrue(urlVal.isValid("http://corndog.io/"));//copied from browser
	       assertFalse(urlVal.isValid("http://cÎ©rndog.icmb/")); //.icbm
	       assertTrue(urlVal.isValid("https://www.nytimes.com/")); //copied from browser
	       assertFalse(urlVal.isValid("https://www.nytimes.cÎ©m/")); //copied from browser
	       assertTrue(urlVal.isValid("https://oregonstate.edu/"));
	       assertFalse(urlVal.isValid("https://Î©regonstate.edu/"));

   }
   
   //Programming Based Test
   public void testProgramTest() 
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   //Unit Test: Path
       assertTrue(urlVal.isValid("http://oregonstate.edu/"));
       assertTrue(urlVal.isValid("http://oregonstate.edu/about"));
       assertTrue(urlVal.isValid("http://oregonstate.edu/"));
       assertTrue(urlVal.isValid("http://oregonstate.edu/michaelpatson"));
       assertTrue(urlVal.isValid("http://oregonstate.edu/about/about"));
       assertFalse(urlVal.isValid("http://oregonstate.edu//.."));
       assertFalse(urlVal.isValid("http://oregonstate.edu/..//file"));

       //Unit Test: Port
       assertFalse(urlVal.isValid("http://oregonstate.edu:65536"));
       assertTrue(urlVal.isValid("http://oregonstate.edu:62341"));
       assertFalse(urlVal.isValid("http://oregonstate.edu:100000"));
       assertTrue(urlVal.isValid("http://oregonstate.edu:22"));

	   
   }
   

   //Random Test
   public void testRandomTest()
   {
	   	//Partition: Scheme
	   		String testSchemePartition[] = new String[10];
	   		
	   		//Valid - even index
	   			//None
	   			testSchemePartition[0] = "";
	   			//Default Scheme(all letters)://
	   			testSchemePartition[2] = "http://";
	   			testSchemePartition[4] = "https://";
	   			testSchemePartition[6] = "ftp://";
	   			//Number/Letter Mix
	   			testSchemePartition[8] = "h3t";
	   		//Invalid - odd index
	   			//No letters
	   			testSchemePartition[1] = "://";
	   			//Missing Part of ://
	   			testSchemePartition[3] = "https/";
	   			testSchemePartition[5] = "https:";
	   			//Null
	   			testSchemePartition[7] = null;
	   			//Begin with number
	   			testSchemePartition[9] = "3http://";
	   	
	   	//Partition: Authority
	   		String testAuthorityPartition[] = new String[8];
	   	
	   		//Valid - even index
	   			//Normal www.letters.com
	   			testAuthorityPartition[0] = "www.amazon.com";
	   			//No www.
	   			testAuthorityPartition[2] = "amazon.com";
	   			//Other country
	   			testAuthorityPartition[4] = "www.amazon.uk";
	   			//numbers.com
	   			testAuthorityPartition[6] = "123.com";
	   		//Invalid - odd index
	   			//Empty
	   			testAuthorityPartition[1] = "";
	   			// .letters
	   			testAuthorityPartition[3] = ".www";
	   			// only letters
	   			testAuthorityPartition[5] = "www";
	   			//letters.
	   			testAuthorityPartition[7] = ".www";
	   			
	   	//Partition: Port
	   		String testPortPartition[] = new String[4];
	   	
	   		//Valid - even index
	   			//Empty 
	   			testPortPartition[0] = "";
	   			//Only Numbers
	   			testPortPartition[2] = ":123";
	   		//Invalid - odd index
	   			//Negative Number
	   			testPortPartition[1] = ":-12";
	   			//Letters
	   			testPortPartition[3] = ":abc";
	   			
	   //Partition: Path
	   		String testPathPartition[] = new String[8];
	   	
	   		//Valid - even index
   				//Empty 
   				testPathPartition[0] = "";
   				// /word/
   				testPathPartition[2] = "/about/";
   				// /word
   				testPathPartition[4] = "/about";
   				// /word/word
   				testPathPartition[6] = "/about/about";
   			//Invalid - odd index
   				//Extra . or /
   				testPathPartition[1] = "/..//about";
   				testPathPartition[3] = "/about//about";
   				testPathPartition[5] = "/..";
   				testPathPartition[7] = "/../";
   				
   		//Randomize URL
   		for(int i = 0; i < 100; i++)
   		{
   			int scheme = (int)(Math.random()*10);
   			int authority = (int)(Math.random()*8);
   			int port = (int)(Math.random()*4);
   			int path = (int)(Math.random()*8);
   			String url = testSchemePartition[scheme] + testAuthorityPartition[authority] + testPortPartition[port] + testPathPartition[path];
   			UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
   			//Sum to get the expected result of true or false
   			int result = (scheme + authority + port + path) % 2;
   			//If even test for true
   			if(result == 0)
   			{
   				assertTrue(urlVal.isValid(url));
   			}
   			else
   			{
   				assertFalse(urlVal.isValid(url));
   			}
   		}		
   }
   
   
}
