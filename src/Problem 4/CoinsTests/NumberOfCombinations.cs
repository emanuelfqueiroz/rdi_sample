using NUnit.Framework;

namespace CoinsTests
{
    public class NumberOfCombinationsTests
    {
       

        [Test]
        public void ValidSolution1()
        {
            Assert.AreEqual(4 , Problem4.Solution.getNumberOfCombinations(10));
        }


        [Test]
        public void ValidSolution2()
        {
            Assert.AreEqual(10, Problem4.Solution.getNumberOfCombinations(20));
        }
    }
}