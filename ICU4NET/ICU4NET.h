// ICU4NET.h

#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Text;

namespace ICU4NET {
	public ref class CharacterIterator
	{
	};

	public ref class Locale
	{
		public:

		System::String^ GetLanguage()
		{
			//return std::abs(1).ToString();
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
			loc->m_native = &icu::Locale::getEnglish();
			return loc;
		}

		static Locale^ GetFrench()
		{
			Locale^ loc = gcnew Locale();
			loc->m_native = &icu::Locale::getFrench();
			return loc;
		}

		static Locale^ GetGerman()
		{
			Locale^ loc = gcnew Locale();
			loc->m_native = &icu::Locale::getGerman();
			return loc;
		}

		static Locale^ GetUS()
		{
			Locale^ loc = gcnew Locale();
			loc->m_native = &icu::Locale::getUS();
			return loc;
		}

		static Locale^ GetRoot()
		{
			Locale^ loc = gcnew Locale();
			loc->m_native = &icu::Locale::getRoot();
			return loc;
		}

		Locale() : m_native(NULL)
		{
		}

	internal:
		const icu::Locale* m_native;
	};

	public ref class BreakIterator
	{
	public:
		System::Boolean IsEqual(BreakIterator^) { return TRUE; }
		BreakIterator^ Clone() { return gcnew ICU4NET::BreakIterator(); }
		CharacterIterator^ GetText() { return gcnew ICU4NET::CharacterIterator(); }
		System::String^ GetCLRText()
		{
			return gcnew System::String(m_bufferedText->getTerminatedBuffer());
		}

		void SetText(String^ text)
		{
			// Pin memory so GC can't move it while native function is called
			pin_ptr<const wchar_t> wch = PtrToStringChars(text);

			if (m_bufferedText != NULL)
				delete m_bufferedText;

			// Make a copy
			m_bufferedText = new UnicodeString(wch);

			// Cannot use stack version here
			// since the text will be freed after 
			// leavning this scope
			m_native->setText(*m_bufferedText);
		}

		void AdoptText(ICU4NET::CharacterIterator^) {}

		System::Int32 First() { return m_native->first(); }

		System::Int32 Last() { return m_native->last(); }

		System::Int32 Previous() { return m_native->previous(); }

		System::Int32 Next() { return m_native->next(); }

		System::Int32 Current() { return m_native->current(); }

		System::Int32 Following(System::Int32 offset) { return m_native->following(offset); }

		System::Int32 Preceding(System::Int32 offset) { return m_native->preceding(offset); }

		System::Boolean IsBoundary(System::Int32 offset) { return m_native->isBoundary(offset); }

		System::Int32 Next(System::Int32 n) { return m_native->next(n); }

		System::Int32 GetRuleStatus() { return m_native->getRuleStatus(); }

		static ICU4NET::BreakIterator^ CreateWordInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu::BreakIterator::createWordInstance(
				icu::Locale::getUS(), status);

			// TODO: check status and throw exception!
			return ret;
		}

		static ICU4NET::BreakIterator^ CreateLineInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu::BreakIterator::createLineInstance(
				*(loc->m_native), status);

			// TODO: check status and throw exception!
			return ret;
		}

		static ICU4NET::BreakIterator^ CreateCharacterInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu::BreakIterator::createCharacterInstance(
				*(loc->m_native), status);

			// TODO: check status and throw exception!
			return ret;
		}

		static ICU4NET::BreakIterator^ CreateSentenceInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu::BreakIterator::createSentenceInstance(
				*(loc->m_native), status);

			// TODO: check status and throw exception!
			return ret;
		}

		static ICU4NET::BreakIterator^ CreateTitleInstance(const ICU4NET::Locale^ loc)
		{
			BreakIterator^ ret = gcnew ICU4NET::BreakIterator();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu::BreakIterator::createTitleInstance(
				*(loc->m_native), status);

			// TODO: check status and throw exception!
			return ret;
		}

		static List<ICU4NET::Locale^>^ GetAvailableLocales()
		{
			List<Locale^>^ col = gcnew List<Locale^>();
			int32_t count;
			const icu::Locale* locs = icu::BreakIterator::getAvailableLocales(count);
			for (int32_t i = 0; i < count; ++i)
			{
				Locale^ loc = gcnew Locale();
				loc->m_native = &locs[i];
				col->Add(loc);
			}

			return col;
		}

		static const int DONE = -1;

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
			if (m_native != NULL)
				delete m_native;
			if (m_bufferedText != NULL)
				delete m_bufferedText;
		}

		BreakIterator() :
			m_native(NULL), m_bufferedText(NULL)
		{

		}

	internal:
		icu::BreakIterator* m_native;
		icu::UnicodeString* m_bufferedText;
	};

	public ref class Normalizer2
	{
	public:

		enum class Mode { Compose, Decompose, FCD, ComposeContiguous };

		String^ Normalize(const String^ src)
		{
			// Pin memory so GC can't move it while native function is called
			pin_ptr<const wchar_t> wch = PtrToStringChars(src);
			UErrorCode status = U_ZERO_ERROR;

			UnicodeString udest = m_native->normalize(wch, status);

			// TODO: check status and throw exception!
			// udest is on the stack.
			return gcnew String(udest.getTerminatedBuffer());
		}

		static ICU4NET::Normalizer2^ GetNFKCCasefoldInstance()
		{
			Normalizer2^ ret = gcnew ICU4NET::Normalizer2();
			UErrorCode status = U_ZERO_ERROR;
			ret->m_native = icu::Normalizer2::getNFKCCasefoldInstance(status);

			// TODO: check status and throw exception!
			return ret;
		}

		static ICU4NET::Normalizer2^ GetInstance(String^ packageName, String^ name, Mode mode)
		{
			UErrorCode status = U_ZERO_ERROR;

			array<Byte>^ utf8PackageName = Encoding::UTF8->GetBytes(packageName);
			array<Byte>^ utf8Name = Encoding::UTF8->GetBytes(name);

			pin_ptr<unsigned char> pinPackageName = &utf8PackageName[0];
			pin_ptr<unsigned char> pinName = &utf8Name[0];

			char * nativePackageName = (char *)pinPackageName;
			char * nativeName = (char *)pinName;

			UNormalization2Mode nativeMode;
			switch (mode)
			{
			case Mode::Compose:
				nativeMode = UNORM2_COMPOSE;
				break;
			case Mode::Decompose:
				nativeMode = UNORM2_DECOMPOSE;
				break;
			case Mode::FCD:
				nativeMode = UNORM2_FCD;
				break;
			case Mode::ComposeContiguous:
				nativeMode = UNORM2_COMPOSE_CONTIGUOUS;
				break;
			default:
				// TODO: throw exception!
				nativeMode = UNORM2_COMPOSE;
				break;
			}

			Normalizer2^ ret = gcnew ICU4NET::Normalizer2();
			ret->m_native = icu::Normalizer2::getInstance((const char *)nativePackageName, (const char *)nativeName, nativeMode, status);

			if (U_FAILURE(status))
			{
				StringBuilder^ msg = gcnew StringBuilder();
				msg->Append("Failed to get normalizer instance '");
				msg->Append(packageName);
				msg->Append("'.'");
				msg->Append(name);
				msg->Append("', mode ");
				msg->Append(mode);
				msg->Append("; error code is ");
				msg->Append(status);
				String^ message = msg->ToString();
				throw gcnew Exception(message);
			}

			// TODO: check status and throw exception!
			return ret;
		}

		~Normalizer2() { CleanUp(); }
	protected:
		!Normalizer2() { CleanUp(); }

	private:
		void CleanUp() 
		{ 
			// Don't delete; objects are singletons
		}

		const icu::Normalizer2* m_native;
	};

	public ref class UData
	{
	public:
		static void SetDataDirectory(String^ path)
		{
			array<Byte>^ utf8Path = Encoding::UTF8->GetBytes(path);
			pin_ptr<unsigned char> pinPath = &utf8Path[0];
			char * nativePath = (char *)pinPath;
			u_setDataDirectory(nativePath);
		}
	};
}
