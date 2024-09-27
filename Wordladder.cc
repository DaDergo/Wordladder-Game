
import <iostream>;
import <sstream>;
import <fstream>;
import <string>;

using namespace std;
/// @brief In this program, you will play a game of wordladder that starts and
// 		ends on the first and second provided arguments respectively.
/// @param argc This will always equal four
/// @param argv This will always have five elements.
/// @return nothing

// onediff(string, string) returns true only if the words provided are the same
// 		length and differ only by one character
bool onediff(string word1, string word2)
{
	int length = word1.length();
	int diffs = 0;
	if (length != word2.length())
	{
		return false;
	}
	for (int i = 0; i < length; ++i)
	{
		if (word1[i] != word2[i])
		{
			diffs++;
		}
	}
	if (diffs != 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool valword(string word1, string wordlist)
{
	if(wordlist.find(word1) != -1){
		return true;
	}
	else return false;
}

int main(int argc, char *argv[])
{
	int bestscore = 0;
	string start = argv[1];
		string end = argv[2];
		string played[9];
		played[0] = start;
		string word;
		string wordlist;
		ifstream words(argv[3]);
		while (words >> word)
		{
			wordlist += word;
			wordlist += " ";
		}
		if (valword(start, wordlist) == false || 
		valword(end, wordlist) == false ||
		start.length() != end.length())
		{
			cerr << "Error: Starting or ending word not found in words file";
			return 1;
		}
	while (true)
	{
		bool win = false;
		
		cout << "Starting Word: " << start << endl;

		for (int i = 1; i < 8; ++i)
		{
			bool rndend = false;
			string input;
			while (!rndend)
			{
				if(cin.eof()){
					return 0;
				}
				cin >> input;
				
				if (valword(input, wordlist))
				{
					if (input == end)
					{
						int score = 8 - i + 1;
						if(score > bestscore){
							bestscore = score;
						}
						cout << "Congratulations! Your Score: "<< score 
						<< ", Best Score: " << bestscore << endl;
						win = true;
						break;
					}
					if (onediff(played[i - 1], input))
					{
						rndend = true;
						bool earlier = false;
						for (int j = 0; j < i; ++j)
						{
							if (onediff(played[j], input))
							{
								earlier = true;
							}
						}
						if (!earlier)
						{
							cerr << "This word could have been played earlier"
								 << endl;
						}
						played[i] = input;
					}
				}
				else
				{
					cerr << "Error: " << input << " does not belong to word file"
						 << endl;
				}
			}
			if(win){
				break;
			}
		}
		if(! win){
			cout << "You lose" << endl;
		return 1;
		}
		
	}
}
