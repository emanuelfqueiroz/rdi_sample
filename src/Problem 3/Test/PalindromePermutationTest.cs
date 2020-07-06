using NUnit.Framework;

namespace Test
{
    public class PalindromePermutationTest
    {
       
        [Test]
        public void ValidSample()
        {
            Assert.AreEqual("YES", Problem3.Program.isPalindromePermutation("carroaco"));
        }
        [Test]
        public void InvalidSample()
        {
            Assert.AreEqual("NO", Problem3.Program.isPalindromePermutation("abcabcabc"));
        }
    }
}