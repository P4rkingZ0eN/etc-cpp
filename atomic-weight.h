map<str,pid>mp;
void SET_DIC(){
mp["H"]={1,1.008};
mp["He"]={2,4.002602};
mp["Li"]={3,6.94};
mp["Be"]={4,9.0121831};
mp["B"]={5,10.81};
mp["C"]={6,12.011};
mp["N"]={7,14.007};
mp["O"]={8,15.999};
mp["F"]={9,18.998403163};
mp["Ne"]={10,20.1797};
mp["Na"]={11,22.98976928};
mp["Mg"]={12,24.305};
mp["Al"]={13,26.9815385};
mp["Si"]={14,28.085};
mp["P"]={15,30.973761998};
mp["S"]={16,32.06};
mp["Cl"]={17,35.45};
mp["Ar"]={18,39.948};
mp["K"]={19,39.983};
mp["Ca"]={20,40.078};
mp["Sc"]={21,44.955908};
mp["Ti"]={22,47.867};
mp["V"]={23,50.9415};
mp["Cr"]={24,51.9961};
mp["Mn"]={25,54.938044};
mp["Fe"]={26,55.845};
mp["Co"]={27,58.933194};
mp["Ni"]={28,58.6934};
mp["Cu"]={29,63.546};
mp["Zn"]={30,65.38};
mp["Ga"]={31,69.723};
mp["Ge"]={32,72.630};
mp["As"]={33,74.921595};
mp["Se"]={34,78.971};
mp["Br"]={35,79.904};
mp["Kr"]={36,83.798};
mp["Rb"]={37,85.4678};
mp["Sr"]={38,87.62};
mp["Y"]={39,88.90584};
mp["Zr"]={40,91.224};
mp["Nb"]={41,92.90637};
mp["Mo"]={42,95.95};
mp["Tc"]={43,98};
mp["Ru"]={44,101.07};
mp["Rh"]={45,102.90550};
mp["Pd"]={46,106.42};
mp["Ag"]={47,107.8682};
mp["Cd"]={48,107.8682};
mp["In"]={49,114.818};
mp["Sn"]={50,118.710};
mp["Sb"]={51,121.760};
mp["Te"]={52,127.60};
mp["I"]={53,126.90447};
mp["Xe"]={54,131.293};
mp["Cs"]={55,132.90545196};
mp["Ba"]={56,137.327};
mp["La"]={57,138.90547};
mp["Ce"]={58,140.116};
mp["Pr"]={59,140.90766};
mp["Nd"]={60,144.242};
mp["Pm"]={61,145};
mp["Sm"]={62,150.36};
mp["Eu"]={63,151.964};
mp["Gd"]={64,157.25};
mp["Tb"]={65,158.92535};
mp["Dy"]={66,162.500};
mp["Ho"]={67,164.93033};
mp["Er"]={68,167.259};
mp["Tm"]={69,168.93422};
mp["Yb"]={70,173.045};
mp["Lu"]={71,174.9668};
mp["Hf"]={72,178.49};
mp["Ta"]={73,180.94788};
mp["W"]={74,183.84};
mp["Re"]={75,186.207};
mp["Os"]={76,190.23};
mp["Ir"]={77,192.217};
mp["Pt"]={78,195.084};
mp["Au"]={79,196.966569};
mp["Hg"]={80,200.592};
mp["Tl"]={81,204.38};
mp["Pb"]={82,207.2};
mp["Bi"]={83,208.98040};
mp["Po"]={84,209};
mp["At"]={85,210};
mp["Rn"]={86,222};
mp["Fr"]={87,223};
mp["Ra"]={88,226};
mp["Ac"]={89,227};
mp["Th"]={90,232.0377};
mp["Pa"]={91,231.03588};
mp["U"]={92,238.0289};
mp["Np"]={93,237};
mp["Pu"]={94,244};
mp["Am"]={95,243};
mp["Cm"]={96,247};
mp["Bk"]={97,247};
mp["Cf"]={98,251};
mp["Es"]={99,252};
mp["Fm"]={100,257};
mp["Md"]={101,258};
mp["No"]={102,259};
mp["Lr"]={103,266};
mp["Rf"]={104,267};
mp["Db"]={105,268};
mp["Sg"]={106,269};
mp["Bh"]={107,270};
mp["Hs"]={108,277};
mp["Mt"]={109,278};
mp["Ds"]={110,281};
mp["Rg"]={111,282};
mp["Cn"]={112,285};
mp["Nh"]={113,286};
mp["Fl"]={114,289};
mp["Mc"]={115,290};
mp["Lv"]={116,293};
mp["Ts"]={117,294};
mp["Og"]={118,294};
}
void element_finder(str a){
    if(mp[a].first==0){
        cout<<"No element\n";
        return;
    }
    cout<<"Number of proton : "<<mp[a].first<<"\nAtomic weight : "<<mp[a].second<<"g/mol\n";
}