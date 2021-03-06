//-*-c++-*------------------------------------------------------------
//
// File name : biogeme.h
// @date   Wed Apr  4 18:01:51 2018
// @author Michel Bierlaire
// @version Revision 1.0
//
//--------------------------------------------------------------------

#ifndef biogeme_h
#define biogeme_h

#include <vector>
#include <set>
#include <map>
#include "bioTypes.h"
#include "bioString.h"

class bioExpression ;
class bioThreadMemory ;
class biogeme {
 public:
  biogeme();
  ~biogeme() ;
  bioReal calculateLikelihood(std::vector<bioReal>& beta,
			      std::vector<bioReal>& fixedBeta) ;
  bioReal calculateLikeAndDerivatives(std::vector<bioReal>& beta,
				      std::vector<bioReal>& fixedBeta,
				      std::vector<bioUInt>& betaIds,
				      std::vector<bioReal>& g,
				      std::vector< std::vector<bioReal> >& h,
				      std::vector< std::vector<bioReal> >& bh,
				      bioBoolean hessian,
				      bioBoolean bhhh) ;
  void simulateFormula(std::vector<bioString> formula,
		       std::vector<bioReal>& beta,
		       std::vector<bioReal>& fixedBeta,
		       std::vector< std::vector<bioReal> >& data,
		       std::vector<bioReal>& results) ;

  void setExpressions(std::vector<bioString> ll,
		      std::vector<bioString> w,
		      bioUInt t) ;
  void setData(std::vector< std::vector<bioReal> >& d) ;
  void setMissingData(bioReal md) ;
  void setDraws(std::vector< std::vector< std::vector<bioReal> > >& draws) ;

private: // methods
  void prepareMemoryForThreads(bioBoolean force = false) ;
  bioReal applyTheFormula(std::vector<bioReal>* g = NULL,
			  std::vector< std::vector<bioReal> >* h = NULL,
			  std::vector< std::vector<bioReal> >* bh = NULL) ;

private: // data
  std::vector<bioString> theLoglike ;
  std::vector<bioString> theWeight ;
  bioUInt nbrOfThreads ;
  std::vector<bioUInt> literalIds ;
  bioBoolean calculateHessian ;
  bioBoolean calculateBhhh ;
  bioThreadMemory* theThreadMemory ;
  std::vector< std::vector<bioReal> > theData ;
  std::vector< std::vector< std::vector<bioReal> > > theDraws ;
  bioReal missingData ;

};
  

#endif
