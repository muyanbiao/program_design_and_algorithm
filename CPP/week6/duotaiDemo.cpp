// 多态示例

// 基类CCreature
class CCreature
{
protected:
	int m_nLifeValue, m_nPower;
public:
	virtual void Attack(CCreature *pCreature) {}
	virtual void Hurted(int nPower) {}
	virtual void FightBack(CCreature *pCreature) {}
};

// 派生类 CDragon、CSoldier、CPhonix、CAngel
class CDragon : public CCreature
{
public:
	virtual void Attack(CCreature *pCreature);
	virtual void Hurted(int nPower);
	virtual void FightBack(CCreature *pCreature);
};

// Attack函数表现攻击动作，攻击某个怪物，并调用被攻击怪物的Hurted函数，
// 以减少被攻击怪物的生命值，同时也调用被攻击怪物的FightBack成员函数，
// 遭受被攻击怪物的反击
void CDragon::Attack(CCreature *pCreature) {
	// 表现攻击动作的代码
	pCreature->Hurted(m_nPower); //多态
	pCreature->FightBack(this); //多态
}

// Hurted函数减少自身生命值，并表现受伤动作
void CDragon::Hurted(nPower) {
	// 表现受伤动作
	m_nLifeValue -= nPower; //多态
}

// FightBack成员函数表现反击动作，并调用被反击对象的Hurted成员函数，
// 使被反击对象手上
void CDragon::FightBack(CCreature *pCreature) {
	// 表现反击动作
	pCreature->Hurted(m_nPower/2); // 多态
}

