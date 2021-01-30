#include "SelectionLayoutModel.hxx"

void SelectionLayoutModel::moveScrollPos(float steps)
{
  m_ScrollPosition = std::clamp(m_ScrollPosition + steps, 0.f, 1.f);
  notifyObservers(Notification{ScrollPosNotif{m_ScrollPosition}});
}

void SelectionLayoutModel::setSelectIndex(int idx)
{
  if (m_SelectedIndex != idx)
  {
    m_SelectedIndex = idx;
    notifyObservers(Notification{SelectItemNotif{m_SelectedIndex}});
  }
}

void SelectionLayoutModel::setHoverIndex(int idx)
{
  if (m_HoverIndex != idx)
  {
    m_HoverIndex = idx;
    notifyObservers(Notification{HoverItemNotif{m_HoverIndex}});
  }
}

float SelectionLayoutModel::getScrollPos() { return m_ScrollPosition; }