/*
**  mod_vortaro - dictionary module for glateo.net
**  Copyright (C) 2023  Olivia May
**
**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.
**
**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.
**
**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef VORTARO_H
#define VORTARO_H

// for 2 dimensional array `dictionary`
enum {
    EO1 = 0,
    EO2,
    EN,
};

// for "x_to_y" arrays
enum {
    FROM = 0,
    TO,
};

// pascal (length cached) strings
typedef char psc1b_str;

typedef struct {
    unsigned int len;
    char str[];
} psc4b_str;

// when adding new words, type \p before the string, ex: "\pHello World!",
// then run `pscv/pscv vortaro.h`.
// also run when changing an existing word's length

#define DICTIONARY_LEN 92
// organized by unicode order (alphabetically except for special chars)
const psc1b_str *dictionary[DICTIONARY_LEN][3] = {

    "\007abadino", "\013abad·in·o", "\006abbess",
    "\010abadiĉo", "\014abad·iĉ·o", "\005abbot",
    "\005abado", "\007abad·o", "\026(gender-neutral) abbot",
    "\010adoltino", "\014adolt·in·o", "\005woman",
    "\011adoltiĉo", "\015adolt·iĉ·o", "\003man",
    "\006adolto", "\010adolt·o", "\005adult",
    "\006avuino", "\012avu·in·o", "\013grandmother",
    "\007avuiĉo", "\013avu·iĉ·o", "\013grandfather",
    "\004avuo", "\006avu·o", "\013grandparent",
    "\007duĉino", "\013duĉ·in·o", "\010dutchess",
    "\010duĉiĉo", "\014duĉ·iĉ·o", "\004duke",
    "\005duĉo", "\007duĉ·o", "\025(gender neutral) duke",
    "\006eŝino", "\012eŝ·in·o", "\004wife",
    "\007eŝiĉo", "\013eŝ·iĉ·o", "\007husband",
    "\004eŝo", "\006eŝ·o", "\006spouse",
    "\006femina", "\010femin·a", "\010feminine",
    "\006femine", "\010femin·e", "\012femininely",
    "\006femino", "\010femin·o", "\005woman",
    "\011fianceino", "\015fiance·in·o", "\010fiancée",
    "\012fianceiĉo", "\016fiance·iĉ·o", "\007fiancé",
    "\007fianceo", "\011fiance·o", "\030(gender neutral) fiancé",
    "\006fizino", "\012fiz·in·o", "\010daughter",
    "\007fiziĉo", "\013fiz·iĉ·o", "\003son",
    "\004fizo", "\006fiz·o", "\033child, (gender neutral) son",
    "\007grofino", "\013grof·in·o", "\010countess",
    "\010grofiĉo", "\014grof·iĉ·o", "\015(title) count",
    "\005grofo", "\007grof·o", "\036(title) (gender neutral) count",
    "\006homino", "\012hom·in·o", "\005woman",
    "\007homiĉo", "\013hom·iĉ·o", "\003man",
    "\004homo", "\006hom·o", "\006person",
    "\003ina", "\005in·a", "\006female",
    "\003ine", "\005in·e", "\006female",
    "\003ino", "\005in·o", "\005woman",
    "\003ipa", "\005ip·a", "\011nonbinary",
    "\003ipe", "\005ip·e", "\011nonbinary",
    "\003ipo", "\005ip·o", "\020nonbinary person",
    "\004iĉa", "\006iĉ·a", "\004male",
    "\004iĉe", "\006iĉ·e", "\004male",
    "\004iĉo", "\006iĉ·o", "\003man",
    "\006kidino", "\012kid·in·o", "\004girl",
    "\007kidiĉo", "\013kid·iĉ·o", "\003boy",
    "\004kido", "\006kid·o", "\003kid",
    "\010kuzenino", "\014kuzen·in·o", "\017(female) cousin",
    "\011kuzeniĉo", "\015kuzen·iĉ·o", "\015(male) cousin",
    "\006kuzeno", "\010kuzen·o", "\027(gender neutral) cousin",
    "\006maskla", "\010maskl·a", "\011masculine",
    "\006maskle", "\010maskl·e", "\013masculinely",
    "\006masklo", "\010maskl·o", "\003man",
    "\010monĥino", "\014monĥ·in·o", "\015(female) monk",
    "\011monĥiĉo", "\015monĥ·iĉ·o", "\013(male) monk",
    "\006monĥo", "\010monĥ·o", "\025(gender neutral) monk",
    "\010neeŝino", "\016ne·eŝ·in·o", "\017unmarried woman",
    "\011neeŝiĉo", "\017ne·eŝ·iĉ·o", "\015unmarried man",
    "\006neeŝo", "\012ne·eŝ·o", "\020unmarried person",
    "\010nepotino", "\014nepot·in·o", "\015granddaughter",
    "\011nepotiĉo", "\015nepot·iĉ·o", "\010grandson",
    "\006nepoto", "\010nepot·o", "\012grandchild",
    "\007nievino", "\013niev·in·o", "\005niece",
    "\010nieviĉo", "\014niev·iĉ·o", "\006nephew",
    "\005nievo", "\007niev·o", "\040nibling, (gender neutral) nephew",
    "\007ontiino", "\013onti·in·o", "\014aunt, auntie",
    "\010ontiiĉo", "\014onti·iĉ·o", "\005uncle",
    "\005ontio", "\007onti·o", "\026(gender neutral) uncle",
    "\011parentino", "\015parent·in·o", "\006mother",
    "\012parentiĉo", "\016parent·iĉ·o", "\006father",
    "\007parento", "\011parent·o", "\006parent",
    "\015petolinfanino", "\023petol·infan·in·o", "\013wicked girl",
    "\016petolinfaniĉo", "\024petol·infan·iĉ·o", "\012wicked boy",
    "\013petolinfano", "\017petol·infan·o", "\014wicked child",
    "\011personino", "\015person·in·o", "\005woman",
    "\012personiĉo", "\016person·iĉ·o", "\003man",
    "\007persono", "\011person·o", "\006person",
    "\016plenkreskulino", "\026plen·kresk·ul·in·o", "\005woman",
    "\017plenkreskuliĉo", "\027plen·kresk·ul·iĉ·o", "\003man",
    "\014plenkreskulo", "\022plen·kresk·ul·o", "\005adult",
    "\010prensino", "\014prens·in·o", "\010princess",
    "\011prensiĉo", "\015prens·iĉ·o", "\006prince",
    "\006prenso", "\010prens·o", "\027(gender neutral) prince",
    "\010rejĝino", "\014rejĝ·in·o", "\005queen",
    "\011rejĝiĉo", "\015rejĝ·iĉ·o", "\004king",
    "\006rejĝo", "\010rejĝ·o", "\035regent, (gender neutral) king",
    "\002ri", "\002ri", "\044(singular) they, (gender neutral) he",
    "\010sahodino", "\014sahod·in·o", "\006sister",
    "\011sahodiĉo", "\015sahod·iĉ·o", "\007brother",
    "\006sahodo", "\010sahod·o", "\007sibling",
    "\007saluton", "\010salut·o", "\005hello",
    "\007siorino", "\013sior·in·o", "\005ma'am",
    "\010sioriĉo", "\014sior·iĉ·o", "\003sir",
    "\005sioro", "\007sior·o", "\054(gender neutral) sir, (gender neutral) ma'am",
    "\007viduino", "\013vidu·in·o", "\005widow",
    "\010viduiĉo", "\014vidu·iĉ·o", "\007widower",
    "\005viduo", "\007vidu·o", "\026(gender neutral) widow",
};

#define EN_TO_EO_LEN 86
// unicode order
const psc1b_str *en_to_eo[EN_TO_EO_LEN][2] = {

    "\006abbess", "\007abadino",
    "\005abbot", "\040(gender neutral) abado; abadiĉo",
    "\005adult", "\024adolto, plenkreskulo",
    "\004aunt", "\007ontiino",
    "\003boy", "\007kidiĉo",
    "\007brother", "\042(gender neutral) sahodo; sahodiĉo",
    "\005child", "\036(offspring) fizo; kido; infano",
    "\005count", "\050(title) (gender neutral) grofo; grofiĉo",
    "\010countess", "\017(title) grofino",
    "\006cousin", "\074(gender neutral) kuzeno; (female) kuzenino; (male) kuzeniĉo",
    "\010daughter", "\006fizino",
    "\004duke", "\040(gender neutral) duĉo; duĉiĉo",
    "\010dutchess", "\007duĉino",
    "\006father", "\012parentiĉo",
    "\006female", "\010ina; ine",
    "\010feminine", "\016femina; femine",
    "\012femininely", "\006femine",
    "\006fiance", "\044(gender neutral) fianceo; fianceiĉo",
    "\007fiancé", "\044(gender neutral) fianceo; fianceiĉo",
    "\007fiancee", "\011fianceino",
    "\010fiancée", "\011fianceino",
    "\004girl", "\006kidino",
    "\012grandchild", "\006nepoto",
    "\015granddaughter", "\010nepotino",
    "\013grandfather", "\007avuiĉo",
    "\013grandmother", "\006avuino",
    "\013grandparent", "\004avuo",
    "\010grandson", "\042(gender neutral) nepoto; nepotiĉo",
    "\002he", "\002ri",
    "\005hello", "\007saluton",
    "\003her", "\023ri, (possesive) ria",
    "\004hers", "\003ria",
    "\002hi", "\007saluton",
    "\003his", "\003ria",
    "\003him", "\002ri",
    "\007husband", "\007eŝiĉo",
    "\001i", "\007mi, min",
    "\003kid", "\004kido",
    "\004king", "\042(gender neutral) rejĝo; rejĝiĉo",
    "\005ma\'am", "\007siorino",
    "\004maam", "\007siorino",
    "\004male", "\012iĉa; iĉe",
    "\003man", "\105(adult) adoltiĉo, plenkreskuliĉo, masklo; homiĉo, personiĉo, iĉo",
    "\011masculine", "\016maskla; maskle",
    "\013masculinely", "\006maskle",
    "\002me", "\007mi, min",
    "\004monk", "\074(gender neutral) monĥo; (female) monĥino; (male) monĥiĉo",
    "\007monkess", "\010monĥino",
    "\006mother", "\011parentino",
    "\006nephew", "\040(gender neutral) nievo; nieviĉo",
    "\007nibling", "\005nievo",
    "\005niece", "\007nievino",
    "\006parent", "\007parento",
    "\006person", "\015homo, persono",
    "\006prince", "\042(gender neutral) prenso; prensiĉo",
    "\010princess", "\010prensino",
    "\005queen", "\010rejĝino",
    "\006regent", "\006rejĝo",
    "\003she", "\002ri",
    "\007sibling", "\006sahodo",
    "\003sir", "\040(gender neutral) sioro; sioriĉo",
    "\006sister", "\010sahodino",
    "\003son", "\007fiziĉo",
    "\006spouse", "\004eŝo",
    "\005their", "\035(singular) ria; (plural) ilia",
    "\006theirs", "\035(singular) ria; (plural) ilia",
    "\004them", "\033(singular) ri; (plural) ili",
    "\004they", "\033(singular) ri; (plural) ili",
    "\005uncle", "\040(gender neutral) ontio; ontiiĉo",
    "\011unmarried", "\006neeŝa",
    "\015unmarried man", "\011neeŝiĉo",
    "\020unmarried person", "\006neeŝo",
    "\017unmarried woman", "\010neeŝino",
    "\002us", "\007ni, nin",
    "\002we", "\007ni, nin",
    "\012wicked boy", "\016petolinfaniĉo",
    "\014wicked child", "\013petolinfano",
    "\013wicked girl", "\015petolinfanino",
    "\005widow", "\037(gender neutral) viduo; viduino",
    "\007widower", "\010viduiĉo",
    "\004wife", "\006eŝino",
    "\005woman", "\100(adult) adoltino, plenkreskulino, femino; homino, personino, ino",
    "\005ya\'ll", "\007vi, vin",
    "\004yall", "\007vi, vin",
    "\003you", "\007vi, vin",
    "\007you all", "\007vi, vin",
};

// convert cx or ch, in `input_word`, to ĉ, etc.
void convert_to_proper_esperanto(char *input_word);

// search from Esperanto to `to_language`, English, etc.
psc4b_str *search_dictionary_eo(const int to_language,
    const char *input_word);

// search from English, etc., to Esperanto
psc4b_str *search_dictionary(const char *wl[][2], const int wordlist_len,
    const char *input_word);

#endif // vortaro.h
