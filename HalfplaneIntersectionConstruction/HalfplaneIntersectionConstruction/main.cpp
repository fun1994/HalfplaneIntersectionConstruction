#include "HalfplaneIntersectionConstruction.h"

void print(Point& p) {
	std::cout << "(" << p.x << ", " << p.y << ")";
}

void print(Halfplane& hp) {
	print(hp.first);
	std::cout << " ";
	print(hp.second);
	std::cout << std::endl;
}

void print(std::vector<Halfplane>& P) {
	for (int i = 0; i < P.size(); i++) {
		print(P[i]);
	}
}

double area2(Point& p, Point& q, Point& r) {
	return p.x * q.y - p.y * q.x + q.x * r.y - q.y * r.x + r.x * p.y - r.y * p.x;
}

bool toLeft(Point& p, Point& q, Point& r) {
	return area2(p, q, r) > 0;
}

Point intersectionPoint(Halfplane& hp1, Halfplane& hp2) {
	double a1 = area2(hp1.first, hp2.first, hp2.second);
	double a2 = area2(hp1.second, hp2.first, hp2.second);
	Point p;
	p.x = a2 / (a2 - a1) * hp1.first.x + a1 / (a1 - a2) * hp1.second.x;
	p.y = a2 / (a2 - a1) * hp1.first.y + a1 / (a1 - a2) * hp1.second.y;
	return p;
}

bool inConvexPolygon(std::vector<Halfplane>& P, Point& p, int index1, int index2) {
	for (int i = 0; i < P.size(); i++) {
		if (i != index1 && i != index2) {
			if (!toLeft(P[i].first, P[i].second, p)) {
				return false;
			}
		}
	}
	return true;
}

bool isBounded(std::vector<Halfplane>& P) {
	if (P.empty()) {
		return true;
	}
	if (P.size() == 1 || P.size() == 2) {
		return false;
	}
	Point p = intersectionPoint(P[0], P[P.size() - 1]);
	if (inConvexPolygon(P, p, 0, P.size() - 1)) {
		return true;
	}
	else {
		return false;
	}
}

bool isSame(std::vector<std::vector<Halfplane>>& P) {
	for (int i = 1; i < P.size(); i++) {
		if (P[0].size() != P[i].size()) {
			return false;
		}
		if (isBounded(P[0])) {
			int index = -1;
			for (int j = 0; j < P[0].size(); j++) {
				if (P[0][0] == P[i][j]) {
					index = j;
					break;
				}
			}
			if (!P[0].empty() && index == -1) {
				return false;
			}
			for (int j = 0; j < P[0].size(); j++) {
				if (!(P[0][j] == P[i][(index + j) % P[0].size()])) {
					return false;
				}
			}
		}
		else {
			for (int j = 0; j < P[0].size(); j++) {
				if (!(P[0][j] == P[i][j])) {
					return false;
				}
			}
		}
	}
	return true;
}

void generateHalfplane(std::vector<std::vector<Halfplane>>& H) {
	Halfplane hp;
	Point p;
	H.push_back(std::vector<Halfplane>());
	p.x = 0.9920707149132403; p.y = 0.07363399384831981; hp.first = p;
	p.x = 0.8793257566015316; p.y = 0.3463277927380687; hp.second = p;
	H[0].push_back(hp);
	p.x = 0.6262843270826522; p.y = 0.11069825023488666; hp.first = p;
	p.x = 0.14967966029784618; p.y = 0.594589792699633; hp.second = p;
	H[0].push_back(hp);
	p.x = 0.9293760965761165; p.y = 0.18056850864908036; hp.first = p;
	p.x = 0.045950407512097; p.y = 0.07177229720412293; hp.second = p;
	H[0].push_back(hp);
	p.x = 0.8352403164119008; p.y = 0.5872157837122858; hp.first = p;
	p.x = 0.4211074597175358; p.y = 0.41287997420517086; hp.second = p;
	H[0].push_back(hp);
	p.x = 0.26222932495465; p.y = 0.012731024760263887; hp.first = p;
	p.x = 0.6299591237230082; p.y = 0.44702877600451685; hp.second = p;
	H[0].push_back(hp);
	p.x = 0.5484177853848199; p.y = 0.7206159612066573; hp.first = p;
	p.x = 0.8666221183840411; p.y = 0.4843533674659727; hp.second = p;
	H[0].push_back(hp);
	H.push_back(std::vector<Halfplane>());
	p.x = 0.3576569464969729; p.y = 0.07284684349840875; hp.first = p;
	p.x = 0.1813563974055724; p.y = 0.9638030328743085; hp.second = p;
	H[1].push_back(hp);
	p.x = 0.6567287592478697; p.y = 0.2504783692774608; hp.first = p;
	p.x = 0.8595109506860636; p.y = 0.7492929807591432; hp.second = p;
	H[1].push_back(hp);
	p.x = 0.36922477452647207; p.y = 0.31693475014125017; hp.first = p;
	p.x = 0.34044154431842544; p.y = 0.20883702447925945; hp.second = p;
	H[1].push_back(hp);
	p.x = 0.7505772742622834; p.y = 0.722235539200711; hp.first = p;
	p.x = 0.39934825864191004; p.y = 0.17594549077606159; hp.second = p;
	H[1].push_back(hp);
	p.x = 0.9027897169649757; p.y = 0.46373487761530063; hp.first = p;
	p.x = 0.003617619362472624; p.y = 0.5363983118758433; hp.second = p;
	H[1].push_back(hp);
	p.x = 0.6843468218170798; p.y = 0.8268677083046259; hp.first = p;
	p.x = 0.7654623250303991; p.y = 0.25151169127022044; hp.second = p;
	H[1].push_back(hp);
	H.push_back(std::vector<Halfplane>());
	p.x = 0.5047848833378645; p.y = 0.5028580370542646; hp.first = p;
	p.x = 0.6571904227160927; p.y = 0.990286289043972; hp.second = p;
	H[2].push_back(hp);
	p.x = 0.5849398195477525; p.y = 0.6568615808002383; hp.first = p;
	p.x = 0.6822973976986599; p.y = 0.4506171724347019; hp.second = p;
	H[2].push_back(hp);
	p.x = 0.9517873800276793; p.y = 0.1806932285493288; hp.first = p;
	p.x = 0.2622527905480523; p.y = 0.585624405540662; hp.second = p;
	H[2].push_back(hp);
	p.x = 0.4015162571204306; p.y = 0.9267349175349826; hp.first = p;
	p.x = 0.11220551003987278; p.y = 0.3279576077584512; hp.second = p;
	H[2].push_back(hp);
	p.x = 0.6669021697254333; p.y = 0.18922034384902242; hp.first = p;
	p.x = 0.27585510715505934; p.y = 0.02468724054734106; hp.second = p;
	H[2].push_back(hp);
	p.x = 0.07620950511738234; p.y = 0.8953007073521521; hp.first = p;
	p.x = 0.4264703600538421; p.y = 0.1782900412135593; hp.second = p;
	H[2].push_back(hp);
	H.push_back(std::vector<Halfplane>());
	p.x = 0.16935822425437796; p.y = 0.22973016567925142; hp.first = p;
	p.x = 0.7486765239093721; p.y = 0.08070717708522024; hp.second = p;
	H[3].push_back(hp);
	p.x = 0.051026642449375825; p.y = 0.3559646986535354; hp.first = p;
	p.x = 0.8838168622088358; p.y = 0.49187870515557053; hp.second = p;
	H[3].push_back(hp);
	p.x = 0.06554497996915232; p.y = 0.1563302304360863; hp.first = p;
	p.x = 0.5357425446835022; p.y = 0.8999639017237849; hp.second = p;
	H[3].push_back(hp);
	p.x = 0.1329818861007529; p.y = 0.2899656114682436; hp.first = p;
	p.x = 0.6339547604466308; p.y = 0.00185280984241043; hp.second = p;
	H[3].push_back(hp);
	p.x = 0.7185220529655455; p.y = 0.6254716768215594; hp.first = p;
	p.x = 0.23291491361533756; p.y = 0.5113311164650564; hp.second = p;
	H[3].push_back(hp);
	p.x = 0.8757643254538701; p.y = 0.43196358159812753; hp.first = p;
	p.x = 0.5008190202534838; p.y = 0.6720340672986526; hp.second = p;
	H[3].push_back(hp);
	H.push_back(std::vector<Halfplane>());
	p.x = 0.8041933528481281; p.y = 0.5037466842547825; hp.first = p;
	p.x = 0.5795981915383481; p.y = 0.44761074498967257; hp.second = p;
	H[4].push_back(hp);
	p.x = 0.7393676664220725; p.y = 0.4080393974161233; hp.first = p;
	p.x = 0.8517518833252048; p.y = 0.019207407277958444; hp.second = p;
	H[4].push_back(hp);
	p.x = 0.05643497624527505; p.y = 0.8812543713003863; hp.first = p;
	p.x = 0.6466831650080249; p.y = 0.589638161942181; hp.second = p;
	H[4].push_back(hp);
	p.x = 0.8980861024610106; p.y = 0.183816796632724; hp.first = p;
	p.x = 0.5729279389946985; p.y = 0.35389761468340364; hp.second = p;
	H[4].push_back(hp);
	p.x = 0.009440243148222227; p.y = 0.48117138044645247; hp.first = p;
	p.x = 0.9961208935120465; p.y = 0.08623306434366462; hp.second = p;
	H[4].push_back(hp);
	p.x = 0.15881634957400992; p.y = 0.5832835587493328; hp.first = p;
	p.x = 0.29167797036791154; p.y = 0.2472579188790861; hp.second = p;
	H[4].push_back(hp);
	H.push_back(std::vector<Halfplane>());
	p.x = 0.1662063766065386; p.y = 0.012526963848440764; hp.first = p;
	p.x = 0.6891028461060351; p.y = 0.3791254807243395; hp.second = p;
	H[5].push_back(hp);
	p.x = 0.6211807035233368; p.y = 0.940637545683772; hp.first = p;
	p.x = 0.26805549868933887; p.y = 0.7033090346609889; hp.second = p;
	H[5].push_back(hp);
	p.x = 0.639137957463621; p.y = 0.5858931688447444; hp.first = p;
	p.x = 0.3177448249141247; p.y = 0.5571604736092003; hp.second = p;
	H[5].push_back(hp);
	p.x = 0.938606749010723; p.y = 0.4940627591151512; hp.first = p;
	p.x = 0.4664539754707946; p.y = 0.02206343202491634; hp.second = p;
	H[5].push_back(hp);
	p.x = 0.774985417779918; p.y = 0.6663913400023104; hp.first = p;
	p.x = 0.12227684018503104; p.y = 0.5713192909001114; hp.second = p;
	H[5].push_back(hp);
	p.x = 0.46907995683277925; p.y = 0.21498714194964985; hp.first = p;
	p.x = 0.7484215656773289; p.y = 0.18855567280038443; hp.second = p;
	H[5].push_back(hp);
	H.push_back(std::vector<Halfplane>());
	p.x = 0.5210904481119353; p.y = 0.778772102857707; hp.first = p;
	p.x = 0.030070444927060236; p.y = 0.6608615537642412; hp.second = p;
	H[6].push_back(hp);
	p.x = 0.8522310377279826; p.y = 0.8457061523374129; hp.first = p;
	p.x = 0.03811273513548019; p.y = 0.8605366388554566; hp.second = p;
	H[6].push_back(hp);
	p.x = 0.10717487406765958; p.y = 0.4752311344320582; hp.first = p;
	p.x = 0.016100400774402557; p.y = 0.32913649408398915; hp.second = p;
	H[6].push_back(hp);
	p.x = 0.9939496464940196; p.y = 0.8578614895573695; hp.first = p;
	p.x = 0.1330128624209863; p.y = 0.9140597464656373; hp.second = p;
	H[6].push_back(hp);
	p.x = 0.8886927883438654; p.y = 0.17568451769955717; hp.first = p;
	p.x = 0.6399488342511037; p.y = 0.6159495830975374; hp.second = p;
	H[6].push_back(hp);
	p.x = 0.5482125136451884; p.y = 0.3257759915213433; hp.first = p;
	p.x = 0.9483478093513207; p.y = 0.024435536077108022; hp.second = p;
	H[6].push_back(hp);
	H.push_back(std::vector<Halfplane>());
	p.x = 0.1464797586326021; p.y = 0.8520836743530208; hp.first = p;
	p.x = 0.9858896384475138; p.y = 0.044861678648024705; hp.second = p;
	H[7].push_back(hp);
	p.x = 0.7214778047066948; p.y = 0.4029865544885012; hp.first = p;
	p.x = 0.22710852760017097; p.y = 0.24112270453658224; hp.second = p;
	H[7].push_back(hp);
	p.x = 0.2273665822769121; p.y = 0.2670832391215229; hp.first = p;
	p.x = 0.8995100434975163; p.y = 0.9200447257693476; hp.second = p;
	H[7].push_back(hp);
	p.x = 0.2868526563225784; p.y = 0.7398357134432682; hp.first = p;
	p.x = 0.5707314248963373; p.y = 0.3522055166033168; hp.second = p;
	H[7].push_back(hp);
	p.x = 0.24843342180547334; p.y = 0.9873848682807354; hp.first = p;
	p.x = 0.06246059979949603; p.y = 0.16649523619127582; hp.second = p;
	H[7].push_back(hp);
	p.x = 0.7503270679139665; p.y = 0.2259176051273708; hp.first = p;
	p.x = 0.8966768394959744; p.y = 0.6101982284305821; hp.second = p;
	H[7].push_back(hp);
	H.push_back(std::vector<Halfplane>());
	p.x = 0.6132519353835947; p.y = 0.1088481962667931; hp.first = p;
	p.x = 0.34258939321181525; p.y = 0.9336252371638637; hp.second = p;
	H[8].push_back(hp);
	p.x = 0.09578265955613852; p.y = 0.20667687080847752; hp.first = p;
	p.x = 0.5817089384149267; p.y = 0.8127327641578747; hp.second = p;
	H[8].push_back(hp);
	p.x = 0.04441383142853461; p.y = 0.355802974962636; hp.first = p;
	p.x = 0.7110199314152016; p.y = 0.5904829047775026; hp.second = p;
	H[8].push_back(hp);
	p.x = 0.887670644359738; p.y = 0.6227947543816781; hp.first = p;
	p.x = 0.10375517142597823; p.y = 0.9175554243965429; hp.second = p;
	H[8].push_back(hp);
	p.x = 0.652736925149907; p.y = 0.3293151218432626; hp.first = p;
	p.x = 0.5310934267579636; p.y = 0.3564446335099746; hp.second = p;
	H[8].push_back(hp);
	p.x = 0.2704628145660791; p.y = 0.03500431583554786; hp.first = p;
	p.x = 0.7893977868635926; p.y = 0.5385652778514713; hp.second = p;
	H[8].push_back(hp);
	H.push_back(std::vector<Halfplane>());
	p.x = 0.4759242369304515; p.y = 0.44577579766606346; hp.first = p;
	p.x = 0.9862183740180449; p.y = 0.08553186289528725; hp.second = p;
	H[9].push_back(hp);
	p.x = 0.1731354362416887; p.y = 0.9154572617230416; hp.first = p;
	p.x = 0.9256907527185484; p.y = 0.7785821038374561; hp.second = p;
	H[9].push_back(hp);
	p.x = 0.000307939049567052; p.y = 0.9715048552341168; hp.first = p;
	p.x = 0.466010429334887; p.y = 0.8107499098081833; hp.second = p;
	H[9].push_back(hp);
	p.x = 0.339793645112889; p.y = 0.5378129828080055; hp.first = p;
	p.x = 0.5908990936097961; p.y = 0.4301854719961995; hp.second = p;
	H[9].push_back(hp);
	p.x = 0.3360853992833669; p.y = 0.054350455253557306; hp.first = p;
	p.x = 0.029798150283480984; p.y = 0.9498129876636109; hp.second = p;
	H[9].push_back(hp);
	p.x = 0.16011085389839796; p.y = 0.17675205398632754; hp.first = p;
	p.x = 0.9420197942216807; p.y = 0.2976929614131718; hp.second = p;
	H[9].push_back(hp);
}

void test() {
	HalfplaneIntersectionConstruction HIC;
	std::vector<std::vector<Halfplane>> H;
	generateHalfplane(H);
	for (int i = 0; i < H.size(); i++) {
		std::vector<std::vector<Halfplane>> C;
		C.push_back(HIC.bruteForce(H[i]));
		C.push_back(HIC.divideAndConquer(H[i]));
		if (!isSame(C)) {
			std::cout << i << std::endl;
			std::cout << "H = " << std::endl;
			print(H[i]);
			std::cout << "bruteForce = " << std::endl;
			print(C[0]);
			std::cout << "divideAndConquer = " << std::endl;
			print(C[1]);
			std::cin.get();
		}
	}
}

int main() {
	test();
	return 0;
}
