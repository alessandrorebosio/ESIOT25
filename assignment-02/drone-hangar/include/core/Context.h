#pragma once

class Context final {
  private:
	bool blinking;

  public:
	Context();

	void startBlink();
	void stopBlink();

	bool &shouldBlink();

	void reset();

	virtual ~Context() = default;
};
