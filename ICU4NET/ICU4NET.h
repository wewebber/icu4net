// ICU4NET.h

#pragma once

using namespace System;
using namespace System::Collections::Generic;

namespace ICU4NET {

	public ref class CharacterIterator
	{
	};

	public ref class Locale
	{
	public:
		
		System::String^ GetLanguage()
		{
			return gcnew String(m_native->getLanguage());
		}

		System::String^ GetScript()
		{
			return gcnew String(m_native->getScript());
		}

		System::String^ GetCountry()
		{
			return gcnew String(m_native->getCountry());
		}

		System::String^ GetVariant()
		{
			return gcnew String(m_native->getVariant());
		}

		System::String^ GetName()
		{
			return gcnew String(m_native->getName());
		}

		System::String^ GetBaseName()
		{
			return gcnew String(m_native->getBaseName());
		}

		static Locale^ GetEnglish()
		{
			Locale^ loc = gcnew Locale();
			loc->m_native = &icu_4_2::Locale::getEnglish();
			return loc;
		}

		static Locale^ GetFrench()
		{
			Locale^ loc = gcnew Locale();
			loc->m_native = &icu_4_2::Locale::getFrench();
			return loc;
		}

		static Locale^ GetGerman()
		{
			Locale^ loc = gcnew Locale();
			loc->m_native = &icu_4_2::Locale::getGerman();
			return loc;
		}

		static Locale^ GetUS()
		{
			Locale^ loc = gcnew Locale();
			loc->m_native = &icu_4_2::Locale::getUS();
			return loc;
		}

		Locale():
			m_native(NULL)
		{
			
		}


			/*
			static const Locale & 	getEnglish (void)
 	Useful constant for this language. 
static const Locale & 	getFrench (void)
 	Useful constant for this language. 
static const Locale & 	getGerman (void)
 	Useful constant for this language. 
static const Locale & 	getItalian (void)
 	Useful constant for this language. 
static const Locale & 	getJapanese (void)
 	Useful constant for this language. 
static const Locale & 	getKorean (void)
 	Useful constant for this language. 
static const Locale & 	getChinese (void)
 	Useful constant for this language. 
static const Locale & 	getSimplifiedChinese (void)
 	Useful constant for this language. 
static const Locale & 	getTraditionalChinese (void)
 	Useful constant for this language. 
static const Locale & 	getFrance (void)
 	Useful constant for this country/region. 
static const Locale & 	getGermany (void)
 	Useful constant for this country/region. 
static const Locale & 	getItaly (void)
 	Useful constant for this country/region. 
static const Locale & 	getJapan (void)
 	Useful constant for this country/region. 
static const Locale & 	getKorea (void)
 	Useful constant for this country/region. 
static const Locale & 	getChina (void)
 	Useful constant for this country/region. 
static const Locale & 	getPRC (void)
 	Useful constant for this country/region. 
static const Locale & 	getTaiwan (void)
 	Useful constant for this country/region. 
static const Locale & 	getUK (void)
 	Useful constant for this country/region. 
static const Locale & 	getUS (void)
 	Useful constant for this country/region. 
static const Locale & 	getCanada (void)
 	Useful constant for this country/region. 
static const Locale & 	getCanadaFrench (void)
 	Useful constant for this country/region. 
static const Locale & 	getDefault (void)
 	Common methods of getting the current default Locale. 
	*/

	internal:
		const icu_4_2::Locale* m_native;
	};

	public ref class BreakIterator
	{
	public:
		System::Boolean IsEqual(BreakIterator^){return TRUE;}
		BreakIterator^ Clone(){return gcnew ICU4NET::BreakIterator();}
		CharacterIterator^ GetText(){return gcnew ICU4NET::CharacterIterator();}
		System::String^ GetCLRText()
		{
			return gcnew System::String(m_bufferedText->getBuffer());
		}
		
		void SetText(String^ text)
		{
			// Pin memory so GC can't move it while native function is called
			pin_ptr<const wchar_t> wch = PtrToStringChars(text);

			if(m_bufferedText != NULL) 
				delete m_bufferedText;
			
			// Make a copy
			m_bufferedText = new UnicodeString(wch);
			
			// Cannot use stack version here
			// since the text will be freed after 
			// leavning this scope
			m_native->setText(*m_bufferedText);
		}

		void AdoptText(ICU4NET::CharacterIterator^){}

		System::Int32 First(){return m_native->first();}

		System::Int32 Last(){return m_native->last();}

		System::Int32 Previous(){return m_native->previous();}

		System::Int32 Next(){return m_native->next();}

		System::Int32 Current(){return m_native->current();}

		System::Int32 Following(System::Int32 offset){return m_native->following(offset);}
		
		System::Int32 Preceding(System::Int32 offset){return m_native->preceding(offset);}
		
		System::Boolean IsBoundary(System::Int32 offset){return m_native->isBoundary(offset);}

		System::Int32 Next(System::Int32 n){return m_native->next(n);};
	
		//createBufferClone
		//isBufferClone
		//getLocale
		//getLocaleId

		static ICU4NET::BreakIterator^ CreateWordInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu_4_2::BreakIterator::createWordInstance(
				*(loc->m_native), status);
			
			// TODO: check status and throw exception!
			return ret;
		}
		static ICU4NET::BreakIterator^ CreateLineInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu_4_2::BreakIterator::createLineInstance(
				*(loc->m_native), status);
			
			// TODO: check status and throw exception!
			return ret;
		}
		static ICU4NET::BreakIterator^ CreateCharacterInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu_4_2::BreakIterator::createCharacterInstance(
				*(loc->m_native), status);
			
			// TODO: check status and throw exception!
			return ret;
		}
		static ICU4NET::BreakIterator^ CreateSentenceInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu_4_2::BreakIterator::createSentenceInstance(
				*(loc->m_native), status);
			
			// TODO: check status and throw exception!
			return ret;
		}
		static ICU4NET::BreakIterator^ CreateTitleInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu_4_2::BreakIterator::createTitleInstance(
				*(loc->m_native), status);
			
			// TODO: check status and throw exception!
			return ret;
		}
		static List<ICU4NET::Locale^>^ GetAvailableLocales()
		{
			List<Locale^>^ col = gcnew List<Locale^>();
			int32_t count;
			const icu_4_2::Locale* locs = icu_4_2::BreakIterator::getAvailableLocales(count);
			for(int32_t i = 0 ; i < count ; ++i)
			{
				Locale^ loc = gcnew Locale();
				loc->m_native = &locs[i];
				col->Add(loc);
			}

			return col;
		}

		static const int DONE = -1;

		//static UnicodeString & 	getDisplayName (const Locale &objectLocale, const Locale &displayLocale, UnicodeString &name)
		//static UnicodeString & 	getDisplayName (const Locale &objectLocale, UnicodeString &name)
		//static URegistryKey 	registerInstance (BreakIterator *toAdopt, const Locale &locale, UBreakIteratorType kind, UErrorCode &status)
		//static UBool 	unregister (URegistryKey key, UErrorCode &status)
		//static StringEnumeration * 	getAvailableLocales (void)

		~BreakIterator()
		{
			// Dispose
			CleanUp();
		}
	protected:
		!BreakIterator()
		{
			// Finalizer
			CleanUp();
		}
	private:

		void CleanUp()
		{
			if(m_native != NULL)
				delete m_native;
			if(m_bufferedText != NULL)
				delete m_bufferedText;
		}

		BreakIterator():
			m_native(NULL),m_bufferedText(NULL)
		{

		}

	internal:

		icu_4_2::BreakIterator* m_native;
		icu_4_2::UnicodeString* m_bufferedText;
	};


}
